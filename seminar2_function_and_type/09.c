#include <stdio.h>
void bob (int* n);
void alice (int* n)
{
    *n = *n*3 + 1;
    printf("Alice: %i\n", *n);
    bob (n);
}
void bob (int* n)
{
    if (*n == 1)
        return;
    if (!(*n%2))
    {
        *n = *n/2;
        printf("Bob:   %i\n", *n);
        bob(n);
    }
    if (*n != 1)
        alice(n);
}
int main()
{
    int a = 13;
    alice(&a);
}