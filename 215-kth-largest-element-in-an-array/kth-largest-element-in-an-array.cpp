class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // nth_element puts the k-th largest element in its sorted position
        // Since we want k-th largest, we look at index n-k from the beginning
        nth_element(nums.begin(), nums.begin() + nums.size() - k, nums.end());
        return nums[nums.size() - k];
    }
};   