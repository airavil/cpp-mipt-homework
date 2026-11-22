#include <stdio.h>
#include <string.h>

int main()
{
    int a[4] = {1819043144, 1461726319, 1684828783, 2593};

    printf("(a) %s\n", (char*)a);

    union
    {
        int arr[4];
        char str[16];
    } u;
    memcpy(u.arr, a, sizeof a);
    printf("(b) %s\n", u.str);

    char buf[16];
    memcpy(buf, a, sizeof a);
    printf("(c) %s\n", buf);
}