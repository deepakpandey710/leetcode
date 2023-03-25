class Solution {
public:
    void dfs(int i,vector<int>adj[],vector<int>&vis,long long &size){
        vis[i]=1;
        size++;
        for(auto &it:adj[i]){
            if(!vis[it]){
                dfs(it,adj,vis,size);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<long long >comp;
        vector<int>adj[n];
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long size=0;
                dfs(i,adj,vis,size);
                comp.push_back(size);
            }
        }
        long long ans=0,sm=0;
        int m=comp.size();
        for(int i=0;i<m;i++){
            ans+=(comp[i]*sm);
            sm+=comp[i];
        
        }
        return ans;
    }
};