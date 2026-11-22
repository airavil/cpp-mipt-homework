#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* concat(const char* a, const char* b)
{
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    char* p = (char*)malloc((len_a + len_b + 1) * sizeof(char));
    if (p == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        return NULL; 
    }
    strcpy(p, a);
    strcat(p, b);
    return p;
}

int main()
{
    char* str1 = "Hello, ";
    char* str2 = "World!";
    char* res = concat(str1, str2);

    if (res != NULL)
    {
        printf("%s\n", res);
        free(res);
    } 
}