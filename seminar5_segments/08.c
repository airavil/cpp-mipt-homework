#include <stdio.h>
#include <stdlib.h>

int sum(int x, int y)    {return x + y;}
int diff(int x, int y)   {return x - y;}
int mult(int x, int y)   {return x * y;}
int sqdiff(int x, int y) {return x * x - y * y;}
int lin(int x, int y)    {return 5 * x - y;}
typedef int (*FuncPtr)(int, int);

int g_x;
int g_y;

void print_func_name(FuncPtr p)
{
    if (p == sum)
        printf("sum\n");
    else if (p == diff)
        printf("diff\n");
    else if (p == mult)
        printf("mult\n");
    else if (p == sqdiff)
        printf("sqdiff\n");
    else if (p == lin)
        printf("lin\n");
    else
        printf("other\n");
}

FuncPtr array[5] = {sum, diff, mult, sqdiff, lin};

void print_array_names(FuncPtr* array, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        print_func_name(array[i]);
}

int compare_funcs(const void* a, const void* b)
{
    FuncPtr f1 = *(FuncPtr*)a;
    FuncPtr f2 = *(FuncPtr*)b;
    int val1 = f1(g_x, g_y);
    int val2 = f2(g_x, g_y);
    return val1 - val2;
}

void sort_funcs(FuncPtr* a, size_t n, int x, int y)
{
    g_x = x;
    g_y = y;
    qsort(a, n, sizeof(FuncPtr), compare_funcs);
}

int main()
{
    print_array_names(array, 5);
    sort_funcs(array, 5, 2, 2);
    print_array_names(array, 5);
    sort_funcs(array, 5, 8, 1);
    print_array_names(array, 5);
}