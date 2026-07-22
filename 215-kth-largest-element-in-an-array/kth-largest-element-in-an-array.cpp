class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // We want the k-th largest, which is the (n-k)-th smallest (0-indexed)
        int target = nums.size() - k;
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int pivotIndex = partition(nums, left, right);
            if (pivotIndex == target) {
                return nums[pivotIndex];
            } else if (pivotIndex < target) {
                left = pivotIndex + 1;
            } else {
                right = pivotIndex - 1;
            }
        }
        return nums[left];
    }

private:
    int partition(vector<int>& nums, int left, int right) {
        // Random pivot to avoid worst-case O(n^2) on sorted inputs
        int pivotIndex = left + rand() % (right - left + 1);
        swap(nums[pivotIndex], nums[right]);
        int pivot = nums[right];
        
        int storeIndex = left;
        for (int i = left; i < right; ++i) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[storeIndex]);
                storeIndex++;
            }
        }
        swap(nums[storeIndex], nums[right]);
        return storeIndex;
    }
};   