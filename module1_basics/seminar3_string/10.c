#include <stdio.h>
#include <string.h>
int main()
{
    int n, k;
    int x = 0, y = 0;
    char a[6];
    char b[3][6] = {"North", "South", "East"};
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a);
        scanf("%i", &k);
        if (!strcmp(a, b[0]))
            y+=k;
        else if (!strcmp(a, b[1]))
            y-=k;
        else if (!strcmp(a, b[2]))
            x+=k;
        else x-=k;
    }
    printf("%i %i\n", x, y);
}