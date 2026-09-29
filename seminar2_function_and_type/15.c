#include <stdio.h>
float yearfrac(int year, int day)
{
    int total_days;
    if (year % 4 == 0)
        total_days = 366;
    else
        total_days = 365;
    return (float)day / total_days;
}
int main()
{
    printf("%.5f\n", yearfrac(2019, 300));
}