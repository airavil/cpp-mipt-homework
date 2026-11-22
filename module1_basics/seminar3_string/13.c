#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int int_err_flag = 0;
int str_to_int(char a[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if (isdigit(a[i]))
            s += ((a[i] - '0') * pow(10, n-1-i));
        else
        {
            int_err_flag = 1;
            return 0;
        }
    }
    return s;
}
int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Error: Wrong number of arguments!\n");
        return 0;
    }
    int len = strlen(argv[1]);
    int probeli[3] = {0};
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (argv[1][i] == ' ')
        {
            probeli[j] = i;
            j++;
        }
        if (j >= 3) break;
    }
    if (probeli[2] != 0 || probeli[1]-probeli[0] != 2 || probeli[0] == 0 || probeli[1] == 0)
    {
        printf("Error: Wrong format!\n");
        return 0;
    }
    int a = str_to_int(argv[1], probeli[0]);
    int b = str_to_int(argv[1] + probeli[1] + 1, len - 1 - probeli[1]);
    if (int_err_flag)
    {
        printf("Error: Operands should be integers!\n");
        return 0;
    }
    if (argv[1][probeli[0]+1] == '+')
        printf("%i\n", a + b);
    else if (argv[1][probeli[0]+1] == '-')
        printf("%i\n", a - b);
    else if (argv[1][probeli[0]+1] == '*')
        printf("%i\n", a * b);
    else if (argv[1][probeli[0]+1] == '%')
        if (b == 0)
            printf("Error: Division by zero!");
        else printf("%i\n", a % b);
    else if (argv[1][probeli[0]+1] == '/')
        if (b == 0)
            printf("Error: Division by zero!");
        else printf("%i\n", a / b);
    else printf("Error: Invalid operator!\n");
}