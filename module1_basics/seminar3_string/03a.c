#include <stdio.h>
int main()
{
    char a;
    scanf("%c", &a);
    if (a > 64 && a < 123 && !(a > 90 && a < 97))
        printf("Letter");
    else if (a > 47 && a < 58)
        printf("Digit");
    else printf("Other");
}