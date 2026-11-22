#include <stdio.h>
#include <string.h>
int main()
{
    char a[1000] = {0};
    char b[1000] = {0};
    scanf("%s%s", a, b);
    int n1 = strlen(a);
    int n2 = strlen(b);
    if (n2 > n1)
        n1 = n2;
    for (int i = 0; i < n1; i++)
        printf("%c%c", a[i], b[i]);
    printf("\n");
}