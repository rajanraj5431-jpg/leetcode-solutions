int longestSubarray(int* nums, int numsSize) {
    int left=0;
    int ocount=0;
    int right=0;
    while(right<numsSize){
        if(nums[right]==0){
            ocount += 1;
        }
        if(ocount>1){
            if(nums[left]==0){
                ocount--;
            }
            left++;
        }
        right++;
    }
    return right-left-1;   
}