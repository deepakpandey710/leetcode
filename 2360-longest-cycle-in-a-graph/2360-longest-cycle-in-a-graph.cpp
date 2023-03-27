class Solution {
public:

    
    void dfs(int i,vector<int>& e,vector<int>& vis,vector<int>& dfsvis,vector<int>&dist,int d,int &ans){
        vis[i]=1;
        dfsvis[i]=1;
        dist[i]=d;
        if(e[i]!=-1){
            if(!vis[e[i]]){
                
                
                dfs(e[i],e,vis,dfsvis,dist,d+1,ans);
            }
            else if(dfsvis[e[i]])
            {
                ans=max(ans,abs(d-dist[e[i]]+1));
            }
            
        }
        dfsvis[i]=0;
        
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size(),ans=-1;
        vector<int>vis(n,0),dfsvis(n,0),dist(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,edges,vis,dfsvis,dist,0,ans);
            }
        }
        return ans;
    }
};