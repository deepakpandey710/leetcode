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
    int mx=-1,cur=0,prev=-1;
    bool isCompleteTree(TreeNode* root) {
        if(!root){
            
            cout<<cur-1<<" "<<mx<<"  "<<endl;
            if((mx-1==cur-1||mx==cur-1)&&cur-1<=prev)
            {
                prev=cur-1;
                return true;
            }
            return false;
        }
        if(!root->left && !root->right){
            cout<<cur<<" "<<mx<<"  "<<root->val<<endl;
            if(mx!=-1&&(cur>prev||mx-1>cur)){
                return false;
            }
            prev=cur;
            mx=max(mx,cur);
            return true;
            
        }
        cur++;
        bool x=isCompleteTree(root->left);
        bool y=isCompleteTree(root->right);
        cur--;
        return  x&&y; 
    }
};