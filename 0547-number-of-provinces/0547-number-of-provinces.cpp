class Solution {
public:
    void dfs(int i,vector<vector<int>> &c,vector<int>&vis){
        vis[i]=1;
        for(int j=0;j<c.size();j++){
            if(!vis[j]&&c[i][j]){
                dfs(j,c,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,isConnected,vis);
            }
        }
        return ans;
    }
};