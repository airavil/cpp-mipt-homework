#include <stdio.h>
int main()
{
    int n;
    int m;
    scanf("%i%i", &n, &m);
    int a[m];
    int sum[m];
    for (int i = 0; i < m; ++i)
            sum[i] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            scanf("%i", &a[j]);
        for (int j = 0; j < m; ++j)
            sum[j]+=a[j];
    }
    for (int i = 0; i < m; ++i)
        printf("%i ", sum[i]);
}