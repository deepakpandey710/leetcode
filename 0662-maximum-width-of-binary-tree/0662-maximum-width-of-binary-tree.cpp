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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int mx=1;
        queue<pair<TreeNode*, long>>q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            long mn=q.front().second;
            long first,last;
            for(int i=0;i<n;i++){
                long curInd=q.front().second-mn;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0)first=curInd;
                if(i==n-1)last=curInd;
                if(node->left)q.push({node->left,curInd*2+1});
                if(node->right)q.push({node->right,curInd*2+2});
            }
            mx=max(mx,int(last-first+1));
        }
        return mx;
    }
};