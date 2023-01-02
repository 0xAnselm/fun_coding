#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **divideString(char *s, int k, char fill, int *returnSize)
{
    int len = strlen(s);
    int div = len / k;
    int rem = fmod(len, k);
    if (rem > 0)
    {
        ++div;
    }
    char **res = (char **)malloc(sizeof(char *) * div);
    for (int i = 0; i < div; ++i)
    {
        res[i] = (char *)malloc(sizeof(char) * (k+1));
        for (int j = 0; j < k; ++j)
        {
            if ((i * k) + j < len)
            {
                res[i][j] = s[i * k + j];
            }
            else
            {
                res[i][j] = fill;
            }
        }
        res[i][k] = '\0';
        // printf("%d: ret: %s, add: %p\n", i, res[i], &res[i]);
    }
    *returnSize = div;
    return res;
}

int main()
{
    char s[] = "abcdefghi";
    int k = 2;
    char fill[] = "x";
    char **res = divideString(s, k, fill[0], &k);
    free(res);
    return 0;
}