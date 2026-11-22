#include <stdio.h>
#include <limits.h>
int main()
{
    int n;
    int max = INT_MIN;
    int len = 1;
    scanf("%i", &n);
    printf("%i ", n);
    do
    {
        ++len;
        if (n % 2 != 0)
            n = 3*n + 1;
        else 
            n = n / 2;
        if (n > max)
            max = n;
        printf("%i ", n);
    }
    while (n != 1);
    printf("\nLength = %i, Max = %i\n", len, max);
}