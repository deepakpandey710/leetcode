class Solution {
    #define ll long long int
    public:
    void dfs(vector<vector<int>> &graph,vector<bool> &visited,int &c,int &i)
    {
        visited[i]=true;
        c++;
        for(int j=0;j<graph[i].size();j++)
        {
            if(!visited[graph[i][j]])
             dfs(graph,visited,c,graph[i][j]);   
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {

        int n=bombs.size();
        vector<vector<int> > graph(n);
        for(int i=0;i<n;i++)
        {
            ll x1,y1,r1;
            x1=bombs[i][0];
            y1=bombs[i][1];
            r1=bombs[i][2];
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                     ll x2,y2,r2;
                     x2=abs(x1-bombs[j][0]);
                     y2=abs(y1-bombs[j][1]);
                    if(x2*x2+y2*y2<=r1*r1)
                    {
                        graph[i].push_back(j);
                    }
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int c=0;
            vector<bool> visited(n,false);
            dfs(graph,visited,c,i);
            ans=max(ans,c);
        }
        return ans;
    }
    
    
// public:
    // int f(int i,vector<vector<int>>& bombs,vector<int>&vis){
    //     int n=bombs.size();
    //     vis[i]=1;
    //     int mx=1;
    //     for(int j=0;j<n;j++){
    //         if(!vis[j]){
    //             long long l=bombs[i][0]-bombs[j][0];
    //             long long m=bombs[i][1]-bombs[j][1];
    //             long long d=sqrt((l*l)+(m*m));
    //             cout<<i<<j<<l<<m<<"  d: "<<d<<" req: "<<bombs[i][2]+bombs[j][2]<<endl;
    //             if(d<=bombs[i][2]+bombs[j][2]){
    //                 mx=max(mx,1+f(j,bombs,vis));
    //             }
    //         }
    //     }
    //     return mx;
    // }
    // int maximumDetonation(vector<vector<int>>& bombs) {
    //     int n=bombs.size();
    //     vector<int>vis(n,0);
    //     return f(0,bombs,vis);
    // }
};