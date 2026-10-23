class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                ans=i;
                break;
            }
            else{
                ans=0;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                ans=ans&i;
            }
        }
        return ans;
    }
};