/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void sum(int* nums, int numsSize, int i) {

    if (i >= numsSize) {
        return;
    }
    
    nums[i] += nums[i - 1];
    sum(nums, numsSize, i + 1);
}

int* runningSum(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    sum(nums, numsSize, 1);
    return nums;
}