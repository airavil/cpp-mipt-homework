#include <stdio.h>
int main()
{
    int a = 0;
    scanf("%i", &a);
    if (a >= 0 && a <= 20 || a > 100 && a < 200 && a % 2)
        printf("Yes");
    else
        printf("No");
}