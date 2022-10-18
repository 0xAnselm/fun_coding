#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int lengthOfLastWord2(char *s)
{
    size_t i = 0;
    int last = 0;
    for (; s[i] != '\0'; ++i)
    {
        size_t j = i + 1;
        while (isspace(s[i]) && s[j] != '\0' && isalpha(s[j]))
        {
            ++j;
        }
        if (j - i - 1 != 0)
        {
            last = j - i - 1;
        }
    }
    return last;
}

int lengthOfLastWord(char *s)
{
    size_t i = strlen(s);
    int l = 0;
    while(i--)
    {
        if (s[i] == 32 && l) {
            break;
        } else if (s[i] != 32) {
            ++l;
        }
    }
    return l;
}

int main()
{
    char s[] = "  abc de ";
    printf("last: %d", lengthOfLastWord(s));
    return 0;
}