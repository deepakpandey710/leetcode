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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* n1=new TreeNode(val);
        if(depth==1){
            n1->left=root;
            return n1;
        }
        queue<TreeNode*>q;
        q.push(root);
        depth--;
        while(!q.empty()){
            depth--;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* cur=q.front(),*l=NULL,*r=NULL;
                q.pop();
                if(cur->left){
                    l=cur->left;
                    q.push(cur->left);
                }
                if(cur->right){
                    r=cur->right;
                    q.push(cur->right);
                }
                if(depth==0){
                    TreeNode* n2=new TreeNode(val);
                    TreeNode* n3=new TreeNode(val);
                    cur->left=n2;
                    cur->right=n3;
                    n2->left=l;
                    n3->right=r;
                }
            }
             if(depth==0)   {
                 return root;
             }
            
        }
        
        return root;
    }
};