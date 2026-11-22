#include <stdio.h>
#include <stdlib.h>
void print_even (int x, int y)
{
    x += abs(x % 2);
    for (; x <= y; x+=2)
        printf("%i ", x);
    printf("\n");
}
int main()
{
    print_even(-7, -3);
}