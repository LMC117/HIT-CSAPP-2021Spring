#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void show_pointer(void *p, char *descr) {
    //    printf("Pointer for %s at %p\n", descr, p);
    printf("%s\t%p\t%lu\n", descr, p, (unsigned long) p);
}

char big_array[1L<<24];    /*  16 MB */
char huge_array[1L<<30];   /*   1 GB */
int global = 0;

int useless() { return 0; }

int main (int argc,char *argv[])
{
    char **env = __environ;    //环境变量__environ 
    void *p1, *p2, *p3, *p4,*p5;
    int local = 0;
    if(argc!=4)
    {
        printf("Usage: LinkAddress P1 P2 P3\n");
	return 1;
    }
    useless(); 
   //打印系统变量信息  
    show_pointer((void *) env, "env");
    int i=0;
    while(*env) 
    { 
	printf("env[%d]\t",i);
	show_pointer((void *) (*env), "*env");
        puts(*env);    
        env++;   i++;
    } 

    p1 = malloc(1L << 28);
    p2 = malloc(1L << 17);
    p3 = malloc( (1L << 17) +1);
    p4 = malloc(1L << 30);
    p5 = malloc(1L << 31);

    show_pointer((void *) big_array, "big array");
    show_pointer((void *) huge_array, "huge array");
    show_pointer((void *) &local, "local");
    show_pointer((void *) &global, "global");
    show_pointer((void *) &argc, "argc");
    show_pointer((void *) argv, "argv");
    printf("argv[0] %16lx\n",(unsigned long) (*argv));
    printf("argv[1] %16lx\n",(unsigned long) (*(argv+1)));    //argv[1]  argv 指针+1 就是argv地址+8
    printf("argv[2] %16lx\n",(unsigned long) (*(argv+2)));
    printf("argv[3] %16lx\n",(unsigned long) (*(argv+3)));
    show_pointer((void *) argv[0], "argv[0]");
    printf("%s\n",argv[0]);
    show_pointer((void *) argv[1], "argv[1]");
    printf("%s\n",argv[1]);
    show_pointer((void *) argv[2], "argv[2]");
    printf("%s\n",argv[2]);
    show_pointer((void *) argv[3], "argv[3]");
    printf("%s\n",argv[3]);
    show_pointer((void *) p1, "p1");
    show_pointer((void *) p2, "p2");
    show_pointer((void *) p3, "p3");
    show_pointer((void *) p4, "p4");
    show_pointer((void *) p5, "p5");

    show_pointer((void *) show_pointer, "show_pointer");
    show_pointer((void *) useless, "useless");
    show_pointer((void *) main, "main");
    show_pointer((void *) exit, "exit");
    show_pointer((void *) printf, "printf");
    show_pointer((void *) malloc, "malloc");
    show_pointer((void *) free, "free");
    free(p1);      free(p2);       free(p3);	    free(p4);         
    return 0;
}
