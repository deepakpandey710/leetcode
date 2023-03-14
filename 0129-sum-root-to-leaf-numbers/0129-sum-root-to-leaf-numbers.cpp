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
    int ans=0,cur=0;
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        if(!root->left&&!root->right){
            
            ans+=cur*10+root->val;
            return ans;
        }
        cur=cur*10+root->val;
        int x=sumNumbers(root->left);
        
        int y=sumNumbers(root->right);
        cur/=10;
        return ans;
    }
};