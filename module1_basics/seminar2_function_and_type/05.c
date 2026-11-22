#include <stdio.h>
void print_binary (int n)
{
    int binaryNum[1000];
    int i = 0;
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%i", binaryNum[j]);
}
int main()
{
    print_binary(4823564);
}