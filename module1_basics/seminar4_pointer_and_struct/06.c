#include <stdio.h>
int exchange(int* pa, int b)
{
    int old_value = *pa;
    *pa = b;
    return old_value;
}
int main()
{
    int a = 10;
    printf("%d\n", exchange(&a, 20));
    printf("%d\n", a); 
}