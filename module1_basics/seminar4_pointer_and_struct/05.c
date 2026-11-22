#include <stdio.h>
#include <math.h>
int solve_quadratic(double a, double b, double c, double* px1, double* px2)
{
    double eps = 1e-10;
    if (fabs(a) < eps)
    {
        if (fabs(b) < eps)
            return 0;
        *px1 = -c / b;
        return 1;
    }
    double D = b * b - 4 * a * c;
    if (D < -eps)
        return 0;
    if (fabs(D) < eps) 
    {
        *px1 = -b / (2 * a);
        return 1;
    }
    double sqrtD = sqrt(D);
    *px1 = (-b - sqrtD) / (2 * a);
    *px2 = (-b + sqrtD) / (2 * a);
    return 2;
}
int main() 
{
    double x1, x2;
    int res;
    res = solve_quadratic(1, -3, 2, &x1, &x2);
    printf("res=%d, x1=%.2f, x2=%.2f\n", res, x1, x2);
    res = solve_quadratic(1, -2, 1, &x1, &x2);
    printf("res=%d, x1=%.2f\n", res, x1);
    res = solve_quadratic(1, 0, 1, &x1, &x2);
    printf("res=%d\n", res);
}