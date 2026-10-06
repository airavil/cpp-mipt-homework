#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
void encrypt( int k, int* c)
{
    if (isupper(*c))
        if (*c + k > 'Z')
            *c = *c + k - 26;
        else *c += k;
    if (islower(*c))
        if (*c + k > 'z')
            *c = *c + k - 26;
        else *c += k;
}
int str_to_int(char a[])
{
    int s = 0;
    int n = strlen(a);
    for (int i = 0; i < n; i++)
        s += ((a[i] - '0') * pow(10, n-1-i));
    return s;
}
int main(int argc, char** argv)
{
    FILE* fr = fopen(argv[1], "r");
    FILE* fw = fopen(argv[2], "w");
    int k = str_to_int(argv[3]);
    int c;
    while ((c = fgetc(fr)) != EOF)
    {
        encrypt(k, &c);
        fprintf(fw, "%c", c);
    }
    fclose(fr);
    fclose(fw);
}