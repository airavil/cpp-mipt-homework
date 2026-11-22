#include <stdio.h>
#include <string.h>
#include <ctype.h>
void encrypt( int k, char* str)
{
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        if (isupper(str[i]))
            if (str[i] + k > 'Z')
                str[i] = str[i] + k - 26;
            else str[i] += k;
        else
            if (str[i] + k > 'z')
                str[i] = str[i] + k - 26;
            else str[i] += k;
    }
}
int main()
{
    char a[10];
    int k = 3;
    scanf("%s", a);
    encrypt(k, a);
    printf("%s\n", a);
}