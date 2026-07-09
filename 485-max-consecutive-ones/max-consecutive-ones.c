int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max_cons=0;
    int count=0;
    for(int i =0;i<numsSize;i++){
        if(nums[i]==1){
            count++;
        }
        if(i==numsSize-1){
            if(max_cons<count){
                max_cons = count;
                count = 0;
            }
        }
        if(nums[i]!=1){
            if(max_cons>=count){
                count = 0;
            }
            if(max_cons<count){
                max_cons = count;
                count = 0;
            }
        }
    }
    return max_cons;
}