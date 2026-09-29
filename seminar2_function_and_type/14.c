#include <stdio.h>
unsigned long long raz(int n, int k)
{
    unsigned long long result = 1;
    for (int i = n; i > n-k; --i)
        result *= i;
    return result;
}
int main()
{
    int n;
    int k;
    scanf("%i%i", &n, &k);
    printf("%llu\n", raz(n, k));
}
