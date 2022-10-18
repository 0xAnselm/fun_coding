#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **divideString(char *s, int k, char fill, int *returnSize)
{
    printf("s:%s, k:%d, fill:%c, ret_size:%d\n", s, k, fill, *returnSize);
    size_t len = strlen(s);
    int div = len / k;
    int rem = fmod(len, k);
    if (rem > 0)
    {
        ++div;
    }
    printf("len: %ld, div: %d, k: %d, rem: %d\n", len, div, k, rem);
    char **res = (char **)malloc(sizeof(char *) * div);
    for (int i = 0; i < div; ++i)
    {
        char *sub = (char *)malloc(sizeof(char) * (k));
        for (int j = 0; j < k; ++j)
        {
            sub[j] = s[i*k+j];
        }
        printf("sub: %s\n", sub);
        res[i] = sub;
        printf("%d: ret: %s, add: %p\n", i, res[i], &res[i]);
    }
    return res;
}

int main()
{
    char s[] = "abcdefghi";
    int k = 5;
    char fill = 'x';
    char **r = divideString(s, k, fill, &k);
    free(r);
    return 0;
}