#include <stdio.h>
float calculate_pi(int n) {
    float sum = 0.0;
    int chis = 1;
    for (int i = 1; i <= n; i++)
    {
        float znam = 2.0 * i - 1.0;
        sum += chis * (1.0 / znam);
        chis = -chis;
    }
    return 4.0 * sum;
}
int main()
{
    int n;
    scanf("%i", &n);
    printf("%.10f\n", calculate_pi(n));
}