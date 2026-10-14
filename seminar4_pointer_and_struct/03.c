#include <stdio.h>
void cube(float* px)
{
    *px = *px * *px * *px;
}
int main()
{
    float a = 4.0;
    cube(&a);
    printf("%f", a);
}