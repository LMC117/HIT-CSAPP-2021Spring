#include "cachelab.h"
#include <assert.h>
#include <errno.h>
#include <getopt.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//#define DEBUG_ON
#define ADDRESS_LENGTH 64

/* Type: Memory address */
typedef unsigned long long int mem_addr_t;

/* Type: Cache line
   LRU is a counter used to implement LRU replacement policy  */
typedef struct cache_line
{
    char valid;
    mem_addr_t tag;
    unsigned long long int lru;
} cache_line_t;

typedef cache_line_t *cache_set_t;
typedef cache_set_t *cache_t;

/* Globals set by command line args */
int verbosity = 0; /* print trace if set */
int s = 0;         /* set index bits */
int b = 0;         /* block offset bits */
int E = 0;         /* associativity */
char *trace_file = NULL;

/* Derived from command line args */
int S; /* number of sets */
int B; /* block size (bytes) */

/* Counters used to record cache statistics */
int miss_count = 0;
int hit_count = 0;
int eviction_count = 0;
unsigned long long int lru_counter = 1;

/* The cache we are simulating */
cache_t cache;
mem_addr_t set_index_mask; //用于从内存地址得到缓存组的索引值

/* 
 * initCache - Allocate memory, write 0's for valid and tag and LRU
 * also computes the set_index_mask
 */
void initCache()
{
    //用二维数组来模拟cache，cache[i][j]代表第i组的第j行
    int i, j;
    // 初始化组
    cache = (cache_t)malloc(sizeof(cache_set_t) * S);
    for (i = 0; i < S; i++)
    {
        // 初始化行
        cache[i] = (cache_set_t)malloc(sizeof(cache_line_t) * E);
        for (j = 0; j < E; j++)
        {
            cache[i][j].valid = 0; // 有效位初始化
            cache[i][j].tag = 0;   // 标记位初始化
            cache[i][j].lru = 0;   // LRU策略标志初始化
        }
    }
}

/* 
 * freeCache - free allocated memory
 */
void freeCache()
{
    int i;
    for (i = 0; i < S; i++)
        free(cache[i]);
    free(cache);
}

/* 
 * accessData - Access data at memory address addr.
 *   If it is already in cache, increast hit_count
 *   If it is not in cache, bring it in cache, increase miss count.
 *   Also increase eviction_count if a line is evicted.
 */
void accessData(mem_addr_t addr)
{
    int i, j;
    int empty_row = -1; // 标志是否有空缺的位置，没有则为-1
    int min_lru, min_lru_row;
    long s_digits, b_digits, t_digits;
    cache_set_t target_group;
    // 获取块偏移
    b_digits = addr & ((1 << b) - 1);
    // 获取组索引
    addr >>= b;
    s_digits = addr & ((1 << s) - 1);
    // 获取标记
    t_digits = (addr >>= s);
    // 锁定目标组
    target_group = cache[s_digits];
    // 对目标组中的每一行进行遍历
    for (i = 0; i < E; i++)
    {
        if (cache[s_digits][i].tag == t_digits) // 先确定有没有tag一致的
            if (cache[s_digits][i].valid == 1)  // 有效位为1，命中当前行
            {
                cache[s_digits][i].lru = lru_counter;
                hit_count++;
                break;
            }
            else if (cache[s_digits][i].valid == 0) // 有效位为0，未命中当前行
                empty_row = i;
    }
    if (i == E) // 没有tag一致的
    {
        miss_count++;
        if (empty_row != -1) // 有空行
        {
            cache[s_digits][empty_row].lru = lru_counter;
            cache[s_digits][empty_row].tag = t_digits;
            cache[s_digits][empty_row].valid = 1;
        }
        else if (empty_row == -1) // 没有空行，需要执行LRU策略
        {
            eviction_count++;
            min_lru_row = 0;
            min_lru = cache[s_digits][0].lru;
            for (j = 1; j < E; j++) // 循环，找到lru值最小的行
            {
                if (cache[s_digits][j].lru < min_lru)
                {
                    min_lru_row = j;
                    min_lru = cache[s_digits][j].lru;
                }
            }
            // 对lru值最小的行进行修改
            cache[s_digits][min_lru_row].lru = lru_counter;
            cache[s_digits][min_lru_row].tag = t_digits;
            cache[s_digits][min_lru_row].valid = 1;
        }
    }
    lru_counter++;
}

/*
 * replayTrace - replays the given trace file against the cache 
 */
void replayTrace(char *trace_fn)
{
    char buf[1000];
    mem_addr_t addr = 0;
    unsigned int len = 0;
    FILE *trace_fp = fopen(trace_fn, "r");

    if (!trace_fp)
    {
        fprintf(stderr, "%s: %s\n", trace_fn, strerror(errno));
        exit(1);
    }

    while (fgets(buf, 1000, trace_fp) != NULL)
    {
        if (buf[1] == 'S' || buf[1] == 'L' || buf[1] == 'M')
        {
            sscanf(buf + 3, "%llx,%u", &addr, &len);

            if (verbosity)
                printf("%c %llx,%u ", buf[1], addr, len);

            accessData(addr);

            /* If the instruction is R/W then access again */
            if (buf[1] == 'M')
                accessData(addr);

            if (verbosity)
                printf("\n");
        }
    }

    fclose(trace_fp);
}

/*
 * printUsage - Print usage info
 */
void printUsage(char *argv[])
{
    printf("Usage: %s [-hv] -s <num> -E <num> -b <num> -t <file>\n", argv[0]);
    printf("Options:\n");
    printf("  -h         Print this help message.\n");
    printf("  -v         Optional verbose flag.\n");
    printf("  -s <num>   Number of set index bits.\n");
    printf("  -E <num>   Number of lines per set.\n");
    printf("  -b <num>   Number of block offset bits.\n");
    printf("  -t <file>  Trace file.\n");
    printf("\nExamples:\n");
    printf("  linux>  %s -s 4 -E 1 -b 4 -t traces/yi.trace\n", argv[0]);
    printf("  linux>  %s -v -s 8 -E 2 -b 4 -t traces/yi.trace\n", argv[0]);
    exit(0);
}

/*
 * main - Main routine 
 */
int main(int argc, char *argv[])
{
    char c;

    while ((c = getopt(argc, argv, "s:E:b:t:vh")) != -1)
    {
        switch (c)
        {
        case 's':
            s = atoi(optarg);
            break;
        case 'E':
            E = atoi(optarg);
            break;
        case 'b':
            b = atoi(optarg);
            break;
        case 't':
            trace_file = optarg;
            break;
        case 'v':
            verbosity = 1;
            break;
        case 'h':
            printUsage(argv);
            exit(0);
        default:
            printUsage(argv);
            exit(1);
        }
    }

    /* Make sure that all required command line args were specified */
    if (s == 0 || E == 0 || b == 0 || trace_file == NULL)
    {
        printf("%s: Missing required command line argument\n", argv[0]);
        printUsage(argv);
        exit(1);
    }

    /* Compute S, E and B from command line args */
    S = 1 << s;
    B = 1 << b;

    /* Initialize cache */
    initCache();

#ifdef DEBUG_ON
    printf("DEBUG: S:%u E:%u B:%u trace:%s\n", S, E, B, trace_file);
    printf("DEBUG: set_index_mask: %llu\n", set_index_mask);
#endif

    replayTrace(trace_file);

    /* Free allocated memory */
    freeCache();

    /* Output the hit and miss statistics for the autograder */
    printSummary(hit_count, miss_count, eviction_count);
    return 0;
}
