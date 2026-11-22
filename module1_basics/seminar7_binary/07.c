#include <stdio.h>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* f = fopen(argv[1], "rb");
    if (f == NULL)
    {
        fprintf(stderr, "Can't open file: %s\n", argv[1]);
        return 1;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fclose(f);

    printf("%ld\n", size);
}