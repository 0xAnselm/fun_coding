#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size);
void printArray(int *nums, int numsSize);

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    const int result_len = nums1Size + nums2Size;
    int result[result_len];
    int p1 = 0;
    int p2 = 0;
    int i = 0;
    while (true && i < 5)
    {
        if (p1 == nums1Size)
        {
            // printf("Break 1\n");
            const ssize_t size = sizeof(int) * (nums2Size - p2);
            memcpy(&result[i], &nums2[p2], size);
            break;
        }
        else if (p2 == nums2Size)
        {
            // printf("Break 2\n");
            const ssize_t size = sizeof(int) * (nums1Size - p2);
            memcpy(&result[i], &nums1[p1], size);
            break;
        }
        if (nums1[p1] <= nums2[p2])
        {
            result[i] = nums1[p1];
            ++p1;
        }
        else
        {
            result[i] = nums2[p2];
            ++p2;
        }
        ++i;
    }
    // printArray(result, result_len);
    if (result_len % 2 == 0)
    {
        double val1 = result[(int)(result_len / 2) - 1];
        double val2 = result[(int)(result_len / 2)];
        double ret_val = (val1 + val2)/2;
        // printf("1. Ret vals: %f %f \t Median %f\n", val1, val2, ret_val);
        return ret_val;
    }
    else
    {
        double ret_val = result[(int)(result_len / 2)];
        // printf("2. Ret vals: %f\n", ret_val);
        return ret_val;
    }
    return EXIT_FAILURE;
}

int main(void)
{
    // int nums1[] = {};
    // int nums2[] = {2,3,4,5,6};
    int nums1[] = {0,0,0,0,0};
    int nums2[] = {-1,0,0,0,0,0,1};
    double a = findMedianSortedArrays(nums1, (int)sizeof(nums1) / sizeof(int), nums2, (int)sizeof(nums2) / sizeof(int));
    printf("Median: %f\nLen Array: %d\n", a, (int)((sizeof(nums1) + sizeof(nums2)) / sizeof(int)));
    return 0;
}

void printArray(int *nums, int numsSize)
{
    printf("Array: ");
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}