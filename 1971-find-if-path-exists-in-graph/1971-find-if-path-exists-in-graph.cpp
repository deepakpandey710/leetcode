class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int>q;
        vector<int>vis(n,0);
        q.push(source);
        vis[source]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            if(x==destination)return true;
            for(auto &it:adj[x]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return false;
    }
};