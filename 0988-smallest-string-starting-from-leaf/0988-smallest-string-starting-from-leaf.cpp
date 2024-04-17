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
    string ans="";
    void f(TreeNode* root, string &res){
        if(!root){
            return;
        }
        if(!root->left &&!root->right){
            res+=root->val+'a';
            string cur=res;
            res.pop_back();
            reverse(cur.begin(),cur.end());
            if(ans.size()==0 || ans>cur){
                ans=cur;
            }
            return;
        }
        res+=root->val+'a';
        f(root->left,res);
        f(root->right,res);
        res.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string res="";
        f(root,res);
        return ans;
    }
};