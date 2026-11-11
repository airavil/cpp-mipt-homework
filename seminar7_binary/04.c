#include <stdio.h>

int is_little_endian()
{
    unsigned int x = 1;
    return *(unsigned char*)&x == 1;
}

int main()
{
    printf("%i\n", is_little_endian());
}