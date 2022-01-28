#include <stdio.h>
#include <stdlib.h>

// Note: The returned array must be malloced, assume caller calls free().
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int *list;
    int *ret;
    int val;

    list = (int *)calloc(numsSize, sizeof(int));
    ret = (int *)calloc(2, sizeof(int));
    ret[0] = -1;
    ret[1] = -1;
    *returnSize = 2;
    for (int i = 0; i < numsSize; ++i) {
        val = target - nums[i];
        for (int j = 0; j < i; ++j) {
            if (list[j] == nums[i]) {
                ret[0] = j;
                ret[1] = i;
                return ret;
            }
        }
        list[i] = val;
    }
    free(list);
    return ret;
}

int main() {
    int *nums;
    int *ans;
    int numsSize;
    int target;
    int returnSize;

    scanf("%d %d", &target, &numsSize);
    nums = (int *)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        scanf("%d", &nums[i]);
    }
    ans = twoSum(nums, numsSize, target, &returnSize);
    printf("%d %d\n", ans[0], ans[1]);

    free(nums);
    free(ans);
}
