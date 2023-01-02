#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* plusOne_attempt1(int* digits, int digitsSize, int* returnSize);

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    int currentPos = digitsSize - 1;
    *returnSize = digitsSize;
    while ((carry != 0) && (currentPos >= 0)) {
        // check if digit at currenPos + 1 overflows
        if ((digits[currentPos] + 1) > 9) {
            digits[currentPos] = 0;
            carry = 1;
        } else {
            digits[currentPos]++;
            carry = 0;
        }
        currentPos--;
    }
    int* result;
    if ((carry == 1) && (currentPos == -1)) {
        *returnSize = digitsSize + 1;
        result = malloc(*returnSize * sizeof(int));
        result[0] = digits[0] + carry;
        memcpy(&result[1], digits, sizeof(int) * digitsSize);
        return result;
    } else if (carry == 0) {
        result = malloc(digitsSize * sizeof(int));
        memcpy(result, digits, sizeof(int) * digitsSize);
        return result;
    }
    return NULL;
}

int main(void) {
    int digitsSize = 4;
    int* digits = malloc(sizeof(int) * digitsSize);
    digits[0] = 4;
    digits[1] = 3;
    digits[2] = 2;
    digits[3] = 1;
    int returnSize = 4;
    int* result = plusOne(digits, digitsSize, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d\n", result[i]);
    }
    free(result);
    free(digits);
}

int* plusOne_attempt1(int* digits, int digitsSize, int* returnSize) {
    uintmax_t val = 0;
    for (int i = 0; i < digitsSize; ++i) {
        val += digits[i] * (uintmax_t)pow(10, digitsSize - 1 - i);
        printf("%ld\n", val);
    }
    val++;
    *returnSize = (int)log10(val) + 1;
    printf("val: %ld, ret size: %d\n", val, *returnSize);
    int* ret = malloc(sizeof(int) * (*returnSize));

    int pos = *returnSize - 1;
    for (int i = 0; i < *returnSize; ++i) {
        uintmax_t power = pow(10, pos - i);
        uintmax_t r = val / power;
        printf("v: %ld, p: %ld, q: %ld", val, power, r);
        ret[i] = r;
        printf("%d\n", ret[i]);
        val -= (ret[i] * power);
    }
    for (int i = 0; i < *returnSize; ++i) {
        printf("%4d", ret[i]);
    }
    return ret;
}