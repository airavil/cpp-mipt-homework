#include <stdio.h>
void mult2_a(int* p, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        *p = *p * 2;
        p += 1;
    }
}
void mult2_b(int* p, size_t n)
{
    for (size_t i = 0; i < n; i++)
        p[i] *= 2;
}
int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    mult2_a(&A[0], 5);
    for (int i = 0; i < 5; i++)
        printf("%i ", A[i]);
    printf("\n");
    mult2_b(&A[0], 5);
    for (int i = 0; i < 5; i++)
        printf("%i ", A[i]);
    printf("\n");
}