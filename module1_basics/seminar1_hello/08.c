#include <stdio.h>
int main()
{
    int a;
    int b;
    int c;
    scanf("%i%i%i", &a, &b, &c);
    a = a / c + 1;
    b = b / c;
    for (int i = a; i <= b; ++i)
        printf("%i ", c*i);
    printf("\n");
}