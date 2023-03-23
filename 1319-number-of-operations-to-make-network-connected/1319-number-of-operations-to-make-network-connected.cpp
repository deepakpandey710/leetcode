class Solution {
public:
    void dfs(int i,vector<int>adj[],vector<int>&vis){
        vis[i]=1;
        for(auto &it:adj[i]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        vector<int>adj[n];
        for(auto &it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int req=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                req++;
                dfs(i,adj,vis);
            }
        }
        return req-1;
        
    }
};