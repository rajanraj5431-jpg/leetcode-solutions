

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){

    int *res;
    int nb, cpt = 0;

    *returnSize = numsSize;    

    nb = numsSize/2;    
    res = (int*)malloc(sizeof(int)*numsSize);
    
    for(int i = 0,  j = 0; i < nb ; i++, j+=2)
    {
        res[j] = nums[i];
        res[j+1] = nums[i+nb];
    }
    return res;
}