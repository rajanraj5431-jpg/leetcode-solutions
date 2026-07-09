int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int count[101] = {0};
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    int running_sum = 0;
    for (int i = 0; i <= 100; i++) {
        int temp = count[i];
        count[i] = running_sum;
        running_sum += temp;
    }
    int* result = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        result[i] = count[nums[i]];
    }
    *returnSize = numsSize;
    return result;

}