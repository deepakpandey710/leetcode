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
     bool preorder(TreeNode* root){
        int le=root->left->val;
        int ri=root->right->val;
        int ro=root->val;
        if(le<2 && ri<2){
            if(ro==2)return le|ri;
            else return le&ri;
        }
        bool lt=le,rt=ri;
        // if(ro==2){
        //     lt=rt=0;
        // }
        // else{
        //     lt=rt=1;
        // }
        if(le>1){
            lt=preorder(root->left);
        }
        if(ri>1){
            rt=preorder(root->right);
        } 
        return ro==2?lt|rt:lt&rt;
    }        
    bool evaluateTree(TreeNode* root) {
        if(root->val<2)return root->val;
        return preorder(root);
    }
};