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
    int ans=0;
    int sumNumbers(TreeNode* root,string res="") {
        if(!root)return ans;
        if(!root->left && !root->right){
            res+=to_string(root->val);
            ans+=stoi(res);
            return ans;
        }
        res=res+to_string(root->val);
        int x =sumNumbers(root->left,res);
        int y =sumNumbers(root->right,res);
        // res.pop_back();
        return ans;
        
    }
};