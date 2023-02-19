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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool r=0;
        while(!q.empty()){
            int size=q.size();
            vector<int>cur(size);
            for(int i=0;i<size;i++ ){
                int ind;
                TreeNode* f=q.front();
                q.pop();
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
                if(r){
                    ind=size-1-i;
                }
                else{
                    ind=i;
                }
                cur[ind]=f->val;
            }
            r=!r;
            ans.push_back(cur);
        }
        return ans;
    }
};