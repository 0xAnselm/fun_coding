#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    uintmax_t val = 0;
    for (int i = 0; i < digitsSize; ++i) {
        val += digits[i] * pow(10, digitsSize - 1 - i);
        printf("%ld\n", val);
    }
    val++;
    val = 6145390195186705544;
    *returnSize = (int)log10(val) + 1;
    printf("val: %ld, ret size: %d\n", val, *returnSize);
    int* ret = malloc(sizeof(int) * (*returnSize));

    int pos = *returnSize - 1;
    for (int i = 0; i < *returnSize; ++i) {
        uintmax_t power = pow(10, pos - i);
        uintmax_t r = val / power;
        printf("v: %ld, p: %ld, q: %lld", val, power, r);
        ret[i] = r;
        printf("%d\n", ret[i]);
        val -= (ret[i] * power);
    }
    for (int i = 0; i < *returnSize; ++i) {
        printf("%4d", ret[i]);
    }
    return ret;
}

int main(void) {
    int digits[] = {6, 1, 4, 5, 3, 9, 0, 1, 9, 5, 1, 8, 6, 7, 0, 5, 5, 4, 3};
    int digitsSize = 19;
    int returnSize = 19;
    plusOne(digits, digitsSize, &returnSize);
}