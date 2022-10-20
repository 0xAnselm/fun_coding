#include <stdio.h>
#include <stdbool.h>
#include <string.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size);
int *merge(int *nums1, int nums1Size, int *nums2, int nums2Size);
void printArray(int* nums, int numsSize);
int* getMedianIdx(int result_len);


double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    const int result_len = nums1Size + nums2Size;
    int result[result_len];
    int p1 = 0;
    int p2 = 0;
    int i = 0;
    while (true && i < 5) {
        if (p1 == nums1Size) {
            // printf("Break 1\n");
            const ssize_t size = sizeof(int)*(nums2Size-p2);
            memcpy(&result[i], &nums2[p2], size);
            break;
        } else if (p2 == nums2Size) {
            // printf("Break 2\n");
            const ssize_t size = sizeof(int)*(nums1Size-p2);
            memcpy(&result[i], &nums1[p1], size);
            break;
        }
        if (nums1[p1] <= nums2[p2]) {
            result[i] = nums1[p1];
            ++p1;
        } else {
            result[i] = nums2[p2];
            ++p2;
        }
        ++i;
    }
    printArray(result, result_len);
    return 2.0;
}

int main(void)
{
    int nums1[] = {1, 3};
    int nums2[] = {2, 7};
    double a = findMedianSortedArrays(nums1, (int)sizeof(nums1) / sizeof(int), nums2, (int)sizeof(nums2) / sizeof(int));
    printf("Median: %f", a);
    return 0;
}

void printArray(int* nums, int numsSize) {
    printf("Array: ");
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

// int* getMedianIdx(int result_len) {
//     if (result_len % 2 == 0) {
//         int ret[2] = {result_len / 2, (result_len / 2) + 1};
//         return ret;
//     }
//     else {
//         int* ret2;
//         *ret2 = (result_len / 2);
//         return ret2;
//     }
// }