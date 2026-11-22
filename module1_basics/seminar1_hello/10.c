#include <stdio.h>
int main()
{
    int n;
    int m = 0;
    scanf("%i", &n);
    int a[n];
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);
    for (int i = 0; i < n-m; ++i)
        if (a[i] < 0)
        {
            ++m;
            for (int j = i; j < n - m; ++j)
                a[j]=a[j+1];
            i = 0;
        }
    for (int i = 0; i < n-m; ++i)
        printf("%i ", a[i]);
}