#include <stdlib.h>

int compare(const void* a, const void* b) {
    int x = (const int)a;
    int y = (const int)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int minimizeSum(int* nums, int numsSize) {
    if (numsSize <= 3) {
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), compare);

    int a = nums[numsSize - 1] - nums[2];
    int b = nums[numsSize - 2] - nums[1];
    int c = nums[numsSize - 3] - nums[0];

    int result = a;

    if (b < result) {
        result = b;
    }

    if (c < result) {
        result = c;
    }

    return result;
}