#include <stdio.h>
int main()
{
    char a;
    int s = 0;
    scanf("%c", &a);
    while (a != '\n')
    {
        s += (a-'0');
        scanf("%c", &a);
    }
    printf("%i", s);
}
