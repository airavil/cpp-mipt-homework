#include <stdio.h>
#include <math.h>
double gamma_func(double x)
{
    const double step = 1e-2;
    const double eps = 1e-10;
    double sum = 0.0;
    double t = 0.0;
    double prev_sum = -1.0;
    while (fabs(sum - prev_sum) > eps)
    {
        prev_sum = sum;
        double f1 = pow(t, x - 1.0) * exp(-t);
        double f2 = pow(t + step, x - 1.0) * exp(-(t + step));
        sum += (f1 + f2) * step / 2.0;
        t += step;
    }
    return sum;
}

int main()
{
    printf("%.5g\n", gamma_func(4.14159));
}