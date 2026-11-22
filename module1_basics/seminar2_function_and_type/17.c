#include <stdio.h>
#include <math.h>
int main()
{
    float x1, y1, r1, x2, y2, r2;
    float d;
    float eps = 1e-5f;
    scanf("%f%f%f", &x1, &y1, &r1);
    scanf("%f%f%f", &x2, &y2, &r2);
    d = sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (fabsf(d - (r1 + r2)) < eps || fabsf(d - fabsf(r1 - r2)) < eps)
        printf("Touch\n");
    else if (d > r1 + r2 || d < fabsf(r1 - r2))
        printf("Do not intersect\n");
    else
        printf("Intersect\n");
}