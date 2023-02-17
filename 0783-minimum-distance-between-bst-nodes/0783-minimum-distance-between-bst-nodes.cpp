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
    int mn=INT_MAX,prev=-1;
    void dfs(TreeNode* root){
        if(!root)return;
        dfs(root->left);
        int x=root->val;
        if(prev!=-1)
            mn=min(mn,abs(x-prev));
        prev=x;
        dfs(root->right);
        
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return mn;
    }
};