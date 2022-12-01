#include <stdio.h>

int uniqueInSubstring(char* sbs, char j, int r) {
    int i = 0;
    while (i < r) {
        if (sbs[i] != j) {
            i++;
        } else {
            return 0;
        }
    }
    printf("\n");
    return i;
}

int lengthOfLongestSubstring(char * s){
    int i = 0;
    int g_max = 1;
    if (s[0] == '\0') {
        return 0;
    }
    while (s[i] != '\0') {
        int r = i+1;
        int l_max = 1;
        // Here we need to search our current substring from s[i..j-1] if s[j] is present
        while(s[r] != '\0' && uniqueInSubstring(&s[i], s[r], r)) {
            r++;
            l_max++;
        }
        // printf("l_max: %d\n\n", l_max);
        if (l_max > g_max) {
            g_max = l_max;
        }
        i++;
    }
    return g_max;
}

int main(void) {
    char s[] = "pwwkew";
    printf("Max substring: %d\n", lengthOfLongestSubstring(s));
    return 0;
}