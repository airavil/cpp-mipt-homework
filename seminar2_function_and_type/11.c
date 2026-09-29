#include <stdio.h>
#define MAX 10
void multiply(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
}
void print_matrix(float M[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%.1f ", M[i][j]);
        printf("\n");
    }
    printf("\n");
}
int main() 
{
    int n = 3;
    float A[MAX][MAX] = {
        {7, 7, 2},
        {1, 8, 3},
        {2, 1, 6}
    };
    float B[MAX][MAX] = {
        {5, 2, 9},
        {-4, 2, 11},
        {7, 1, -5}
    };
    float C[MAX][MAX];
    multiply(A, B, C, n);
    print_matrix(C, n);
}