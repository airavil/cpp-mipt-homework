#include <stdio.h>
#include <stdlib.h>
float* get_geometric_progression(float a, float r, int n)
{
    float* p = (float*)malloc(n * sizeof(float));
    if (p == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }
    p[0] = a; 
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] * r;
    }
    return p;
}
int main()
{
    float a = 1.0;
    float r = 3.0;
    int n = 10;
    float* res = get_geometric_progression(a, r, n);
    if (res != NULL)
    {
        for (int i = 0; i < n; i++)
            printf("%.1f ", res[i]);
        printf("\n");
        free(res);
    }
}