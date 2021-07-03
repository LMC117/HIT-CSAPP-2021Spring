/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1xB direct mapped cache with a blocx size of 32 bytes.
 */
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    if (M == 32 && N == 32)
    {
        int i, j, x;
        int t0, t1, t2, t3, t4, t5, t6, t7;
        for (i = 0; i < M; i += 8)
            for (j = 0; j < N; j += 8)
            {
                for (x = i; x < (i + 8); x++)
                {
                    t0 = A[x][j];
                    t1 = A[x][j + 1];
                    t2 = A[x][j + 2];
                    t3 = A[x][j + 3];
                    t4 = A[x][j + 4];
                    t5 = A[x][j + 5];
                    t6 = A[x][j + 6];
                    t7 = A[x][j + 7];
                    B[j][x] = t0;
                    B[j + 1][x] = t1;
                    B[j + 2][x] = t2;
                    B[j + 3][x] = t3;
                    B[j + 4][x] = t4;
                    B[j + 5][x] = t5;
                    B[j + 6][x] = t6;
                    B[j + 7][x] = t7;
                }
            }
    }
    if (M == 64 && N == 64)
    {
        int i, j;
        int x;
        int tmp;
        int t0, t1, t2, t3, t4, t5, t6, t7;
        for (i = 0; i < N; i += 8)
            for (j = 0; j < M; j += 8)
            {
                for (x = i; x < i + 4; ++x)
                {
                    t0 = A[x][j + 0];
                    t1 = A[x][j + 1];
                    t2 = A[x][j + 2];
                    t3 = A[x][j + 3];
                    t4 = A[x][j + 4];
                    t5 = A[x][j + 5];
                    t6 = A[x][j + 6];
                    t7 = A[x][j + 7];

                    B[j][x] = t0;
                    B[j + 1][x] = t1;
                    B[j + 2][x] = t2;
                    B[j + 3][x] = t3;
                    B[j][x + 4] = t4;
                    B[j + 1][x + 4] = t5;
                    B[j + 2][x + 4] = t6;
                    B[j + 3][x + 4] = t7;
                }
                for (x = j; x < j + 4; ++x)
                {
                    t0 = A[i + 4][x];
                    t4 = A[i + 4][x + 4];
                    t1 = A[i + 5][x];
                    t5 = A[i + 5][x + 4];
                    t2 = A[i + 6][x];
                    t6 = A[i + 6][x + 4];
                    t3 = A[i + 7][x];
                    t7 = A[i + 7][x + 4];

                    tmp = B[x][i + 4];
                    B[x][i + 4] = t0;
                    t0 = tmp;
                    tmp = B[x][i + 5];
                    B[x][i + 5] = t1;
                    t1 = tmp;
                    tmp = B[x][i + 6];
                    B[x][i + 6] = t2;
                    t2 = tmp;
                    tmp = B[x][i + 7];
                    B[x][i + 7] = t3;
                    t3 = tmp;

                    B[x + 4][i + 0] = t0;
                    B[x + 4][i + 1] = t1;
                    B[x + 4][i + 2] = t2;
                    B[x + 4][i + 3] = t3;
                    B[x + 4][i + 4] = t4;
                    B[x + 4][i + 5] = t5;
                    B[x + 4][i + 6] = t6;
                    B[x + 4][i + 7] = t7;
                }
            }
    }
    if (M == 61 && N == 67)
    {
        int i, j, x, y;
        for (i = 0; i < N; i += 16)
            for (j = 0; j < M; j += 16)
                for (x = i; (x < i + 16) && (x < N); x++)
                    for (y = j; (y < j + 16) && (y < M); y++)
                        B[y][x] = A[x][y];
    }
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }
}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc);

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc);
}

/* 
 * is_transpose - This helper function checxs if B is the transpose of
 *     A. You can checx the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; ++j)
        {
            if (A[i][j] != B[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}
