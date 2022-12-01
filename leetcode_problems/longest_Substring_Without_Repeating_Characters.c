#include <stdio.h>

int uniqueInSubstring(char* sbs, char c, int j) {
    int i = 0;
    while (i < j) {
        if (sbs[i] != c) {
            i++;
        } else {
            return 0;
        }
    }
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
        int j = 1;
        int l_max = 1;
        /* Here we need to search our current substring from s[i..j-1] if s[j] is present:
        If yes leave current local longest substring and inc i
        If not inc local longest substring length l_max
        */
        while(s[r] != '\0' && uniqueInSubstring(&s[i], s[r], j)) {
            r++;
            j++;
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