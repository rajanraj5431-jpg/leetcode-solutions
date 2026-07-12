class Solution {
public:
    unordered_map<long long, int> mp;
    int count = 0;

    void dfs(TreeNode* root, long long sum, int targetSum) {
        if (root == NULL) return;

        sum += root->val;

        // If previous prefix sum was (sum - target),
        // the path between them has sum = target
        count += mp[sum - targetSum];

        mp[sum]++;

        dfs(root->left, sum, targetSum);
        dfs(root->right, sum, targetSum);

        // Backtrack: remove current path's prefix sum
        mp[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;  // handles paths starting from root
        dfs(root, 0, targetSum);
        return count;
    }
};