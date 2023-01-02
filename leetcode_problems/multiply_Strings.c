#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printA(int* result, int size) {
    int i = 0;
    for (; i < size; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

char* multiply(char* num1, char* num2) {
    int p = (int)(strlen(num1));  // length number 1
    int q = (int)(strlen(num2));  // length number 2

    int* result = calloc((p + q + 1), sizeof(int));
    result[p + q + 1] = '\0';
    int resultSize = p + q;
    int a_i;  // pointer left factor
    int b_i;  // pointer right factor

    for (b_i = 0; b_i < q; ++b_i) {
        int carry = 0;
        for (a_i = p - 1; -1 < a_i; --a_i) {
            int idx = a_i + b_i + 1;
            int n = (int)num1[a_i] - 48;
            int m = (int)num2[b_i] - 48;
            int val = carry + n * m;
            result[idx] += val;
            carry = result[idx] / 10;
            result[idx] = (char)result[idx] % 10;
            // printf("n:%d m:%d v:%d\n", n, m, val);
            // printA(result, resultSize);
        }
        result[b_i] += carry;
    }

    return result;
}

int* multiplyInt(char* num1, char* num2) {
    int p = (int)(strlen(num1));  // length number 1
    int q = (int)(strlen(num2));  // length number 2

    int* result = calloc((p + q), sizeof(int));
    // result[p + q + 1] = '\0';
    int resultSize = p + q;
    int a_i;  // pointer left factor
    int b_i;  // pointer right factor

    for (b_i = 0; b_i < q; ++b_i) {
        int carry = 0;
        for (a_i = p - 1; -1 < a_i; --a_i) {
            int idx = a_i + b_i + 1;
            int n = (int)num1[a_i] - 48;
            int m = (int)num2[b_i] - 48;
            int val = carry + n * m;
            result[idx] += val;
            carry = result[idx] / 10;
            result[idx] = result[idx] % 10;
            printf("n:%d m:%d v:%d\n", n, m, val);
            printA(result, resultSize);
        }
        result[b_i] += carry;
    }

    return result;
}

int main() {
    char* num1 = "195";
    char* num2 = "12653";

    char* result = multiply(num1, num2);
    printA(result, (int)(strlen(num1) + strlen(num2)));
    return 0;
}