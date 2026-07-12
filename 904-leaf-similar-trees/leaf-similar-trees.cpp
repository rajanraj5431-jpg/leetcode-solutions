class Solution {
public:
    void dfs(TreeNode* root, vector<int>& leaves) {
        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL) {
            leaves.push_back(root->val);
            return;
        }

        dfs(root->left, leaves);
        dfs(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;

        dfs(root1, arr1);
        dfs(root2, arr2);

        return arr1 == arr2;
    }
};