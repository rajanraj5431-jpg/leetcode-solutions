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
    int count=0;
    int maxi=0;
    void dfsleft(TreeNode* root){
        if(root==NULL){
            return;
        }
        count++;
        dfsright(root->left);
        maxi=max(maxi, count);
        count=0;
        dfsleft(root->right);
    }
    void dfsright(TreeNode* root){
        if(root==NULL){
            return;
        }
        count++;
        dfsleft(root->right);
        maxi=max(maxi,count);
        count=0;
        dfsright(root->left);
    }
    int longestZigZag(TreeNode* root) {
        dfsleft(root->right);
        dfsright(root->left);
        return maxi;
    }
};