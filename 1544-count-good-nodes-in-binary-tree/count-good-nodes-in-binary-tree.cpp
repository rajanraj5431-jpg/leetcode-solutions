/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int maxi){
        if(root==NULL){
            return 0;
        }
        int good=0;
        if(root->val>=maxi){
            good=1;
        }
        else{
            good=0;
        }
        int new_max=max(root->val,maxi);
        return good + dfs(root->left, new_max) + dfs(root->right, new_max);
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};