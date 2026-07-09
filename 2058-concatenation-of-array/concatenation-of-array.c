/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int n = 2 * numsSize;
    *returnSize = n;
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i=0;i<numsSize;i++){
        arr[i] = nums[i];
        arr[i+numsSize] = nums[i];
    }
    return arr;
}