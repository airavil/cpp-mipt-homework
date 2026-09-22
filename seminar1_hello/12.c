#include <stdio.h>
int sum(int x)
{
    int s = 0;
    while (x)
    {
        s += x%10;
        x = x/10;
    }
    return s;
}
int main()
{
    int n;
    scanf("%i", &n);
    int a[n];
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < n - 1 - j; ++i)
        {
            if (sum(a[i]) > sum(a[i + 1]))
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);
}