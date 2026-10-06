#include <stdio.h>
#include <string.h>
void is_palindrom (char a[])
{
    int n = strlen(a);
    for (int i = 0; i < n/2; i++)
        if (a[i] != a[n-1-i])
        {
            printf("No\n");
            return;
        }
    printf("Yes\n");
}
int main()
{
    char a[10];
    scanf("%s", a);
    is_palindrom(a);
}