class Solution {
public:
    int f(int s,int &d, int k,vector<vector<int>>adj[],vector<vector<int>>&dp){
        if(s==d){
            return 0;
        }
        if(k<0) return 1e9;
        if(dp[s][k]!=-1)return dp[s][k];
        int ans=1e9;
        for(auto &it:adj[s]){
            ans=min(ans,it[1]+f(it[0],d,k-1,adj,dp));
        }
        return dp[s][k]=ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>adj[n],dp(n,vector<int>(k+1,-1));
        
        for(auto &it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        int ans=f(src,dst,k,adj,dp);
        return ans>=1e9?-1:ans;
    }
};