#include <stdio.h>
#include <string.h>
#include "list.h"

DECLARE_LIST(float)

void print_float(float x)
{
    printf("%f", x);
}

int main()
{
    List_float c = list_float_init(0);
    for (int i = 0; i < 10; ++i)
        list_float_push_back(&c, i * 0.1f);

    list_float_print(&c, print_float);
    list_float_destroy(&c);
}