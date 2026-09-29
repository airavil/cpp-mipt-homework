#include <stdio.h>
#define MAX 10
void assign(float A[MAX][MAX], float B[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = B[i][j];
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
    float B[MAX][MAX] = {
        {1.1, 2.2, 3.3},
        {4.4, 5.5, 6.6},
        {7.7, 8.8, 9.9}
    };
    float A[MAX][MAX] = {0};
    print_matrix(B, n);
    assign(A, B, n);
    print_matrix(A, n);
}