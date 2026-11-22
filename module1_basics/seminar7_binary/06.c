#include <stdio.h>
#include <stdlib.h>

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

    if (fseek(f, 0, SEEK_END) != 0)
    {
        fprintf(stderr, "fseek error\n");
        fclose(f);
        return 1;
    }
    long size = ftell(f);
    if (size < 3)
    {
        fprintf(stderr, "File is too small\n");
        fclose(f);
        return 1;
    }

    fseek(f, size - 3, SEEK_SET);
    unsigned char buf[3];
    fread(buf, 1, 3, f);
    fclose(f);

    for (int i = 0; i < 3; ++i)
        printf("%02X ", buf[i]);
    printf("\n");

    for (int i = 0; i < 3; ++i)
        putchar((buf[i] >= 32 && buf[i] < 127) ? buf[i] : '.');
    putchar('\n');
}