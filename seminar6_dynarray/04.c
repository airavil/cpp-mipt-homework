#include <stdio.h>

int main()
{
#ifndef COUNT
    printf("No count!\n");
#endif

#if COUNT > 100
    printf("Count is too large!\n");
#endif

#ifdef REVERSE
    for (int i = COUNT; i >= 1; --i)
        printf("%i ", i);
#else
    for (int i = 1; i <= COUNT; ++i)
        printf("%i ", i);
#endif
    printf("\n");
}