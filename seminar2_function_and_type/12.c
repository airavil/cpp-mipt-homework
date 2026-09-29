#include <stdio.h>
#define MAX 10
void assign(int A[MAX][MAX], int B[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = B[i][j];
}
void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
}
void power(int A[MAX][MAX], int C[MAX][MAX], int n, int k)
{
    int B[MAX][MAX];
    assign(B, A, n);
    assign(C, A, n);
    for (int i = 0; i < k-1; i++)
    {
        multiply(A, B, C, n);
        assign(B, C, n);
    }
}
void print_matrix(int M[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%i ", M[i][j]);
        printf("\n");
    }
    printf("\n");
}
int main()
{
    int n = 3;
    int k = 4;
    int A[MAX][MAX] = {
        {7, 7, 2},
        {1, 8, 3},
        {2, 1, 6}
    };
    int C[MAX][MAX] = {0};
    power(A, C, n, k);
    print_matrix(C, n);
}