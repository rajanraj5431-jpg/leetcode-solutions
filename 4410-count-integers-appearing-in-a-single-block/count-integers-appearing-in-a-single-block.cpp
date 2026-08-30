class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }
        int ans=0;
        unordered_map <int, int> freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        int len=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                len++;
            }
            if(nums[i]!=nums[i+1]){
                if(len==freq[nums[i]]){
                    ans++;
                }
                len=1;
            }
        }
        if (len == freq[nums[n - 1]]) {
            ans++;
        }
        return ans;
    }
};