#include <stdio.h>
#include <string.h>
#include <math.h>
int str_to_int(char a[])
{
    int s = 0;
    int n = strlen(a);
    for (int i = 0; i < n; i++)
        s += ((a[i] - '0') * pow(10, n-1-i));
    return s;
}
int main(int argc, char** argv)
{
    int n = str_to_int(argv[2]);
    for (int i = 0; i < n; i++)
        printf("%s ", argv[1]);
    printf("\n");
}