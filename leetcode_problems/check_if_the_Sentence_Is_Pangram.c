#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool checkIfPangram(char *s)
{
    if (s == NULL)
    {
        return false;
    }
    size_t count = 0;

    for (size_t i = 0; s[i] != '\0'; ++i)
    {
        if (isalpha((unsigned char)s[i]))
        {
            char c = tolower((unsigned char)s[i]);
            printf("%c\n", c);
            size_t j = 0;
            while (j != i && c != tolower((unsigned char)s[j]))
                ++j;

            if (j == i)
                ++count;
        }
    }
    return count == 26 ? true : false; 
}

int main()
{
    char sentence[] = "thequickbrownfoxjumpsoverthelazydog";
    checkIfPangram(sentence);
    return 0;
}