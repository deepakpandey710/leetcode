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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int isOdd=1;
        while(!q.empty()){
            int n=q.size();
            int p=isOdd?INT_MIN:INT_MAX;
            for(int i=0;i<n;i++){
                TreeNode* f=q.front();
                if(isOdd){
                   if(f->val<=p || f->val%2!=1)return false;
                }else{
                    if(f->val>=p || f->val%2!=0)return false;
                }
                p=f->val;
                q.pop();
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
                
            }
            isOdd=!isOdd;
        }
        
        return true;
    }
};