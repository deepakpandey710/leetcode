class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n,-1);
        vector<vector<int>>vis(n,vector<int>(2,0));
        ans[0]=0;
        vector<vector<int>>adj[n];
        for(auto &it:redEdges){
            adj[it[0]].push_back({it[1],0});
        }
        for(auto &it:blueEdges){
            adj[it[0]].push_back({it[1],1});
        }
        vis[0][0]=1;
        vis[0][1]=1;
        queue<vector<int>>q;
        for(auto &it:adj[0]){
            vis[it[0]][it[1]]=1;
            it.push_back(1);
            q.push(it);
        }
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            if(ans[x[0]]==-1)
                ans[x[0]]=x[2]; 
            for(auto &it:adj[x[0]]){
                if(x[1]!=it[1] && !vis[it[0]][it[1]]){
                    vis[it[0]][it[1]]=1;
                    it.push_back(x[2]+1);
                    q.push(it);
                }
            }
        }
        return ans;
    }
};