#include <stdio.h>
#include <string.h>
void used_chars(const char* str, char* used)
{
    int seen[26] = {0};
    while (*str)
    {
        char ch = *str;
        if (ch >= 'a' && ch <= 'z')
            seen[ch - 'a'] = 1;
        else if (ch >= 'A' && ch <= 'Z')
            seen[ch - 'A'] = 1;
        str++;
    }
    int idx = 0;
    for (int i = 0; i < 26; i++)
        if (seen[i])
        {
            used[idx] = 'a' + i;
            idx++;
        }
    used[idx] = '\0';
}
int main()
{
    char s[50] = "Sapere Aude";
    char u[30];
    used_chars(s, u);
    printf("%s\n", u);
    strcpy(s, "123!@#$");
    used_chars(s, u);
    printf("%s\n", u);
    strcpy(s, "The Quick Brown Fox Jumps Over The Lazy Dog!");
    used_chars(s, u);
    printf("%s\n", u);
}