int longestOnes(int* nums, int numsSize, int k) {
    int left=0;
    int ocount=0;
    int right=0;
    while(right<numsSize){
        if(nums[right]==0){
            ocount += 1;
        }
        if(ocount>k){
            if(nums[left]==0){
                ocount--;
            }
            left++;
        }
        right++;
    }
    return right-left;
}