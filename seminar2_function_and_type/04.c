#include <stdio.h>
int sum_of_digits (int x)
{
    int s = 0;
    do
    {
        s += x % 10;
        x = x / 10;
    }
    while (x != 0);
    return s;
}
int main()
{
    printf("%i\n", sum_of_digits(55955));
}