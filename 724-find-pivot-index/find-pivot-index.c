int pivotIndex(int* nums, int numsSize) {
    int *arr=(int *)calloc(numsSize,sizeof(int));
    int *aar=(int *)calloc(numsSize,sizeof(int));
    for(int i=1;i<numsSize;i++){
        arr[i]=nums[i-1]+arr[i-1];
    }
    for(int i=numsSize-2;i>=0;i--){
        aar[i]=aar[i+1]+nums[i+1];
    }
    for(int i=0;i<numsSize;i++){
        if(aar[i]==arr[i]){
            return i;
        }
    }
    return -1;
}