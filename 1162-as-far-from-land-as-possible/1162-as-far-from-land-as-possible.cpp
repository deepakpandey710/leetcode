class Solution {
public:

    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0)),dist(n,vector<int>(n,0));
        queue<vector<int>>q;
        int ans=0;
        for(int i=0;i<n;i++ ){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }
        vector<int>d={-1,0,1,0,-1};
        if(q.size()==0|| q.size()==n*n){
            return -1;
        }
        while(!q.empty()){
            vector<int>x=q.front();
            q.pop();
            dist[x[0]][x[1]]=x[2];
            for(int i=0;i<4;i++){
                int l=x[0]+d[i],m=x[1]+d[i+1];
                if(l<n && m<n && l>=0 && m>=0 && !vis[l][m]){
                    vis[l][m]=1;
                    q.push({l,m,x[2]+1});
                }
            }
        }
        for(int i=0;i<n;i++ ){
            for(int j=0;j<n;j++){
                ans=max(ans,dist[i][j]);
            }
        }
        return ans;
    }
};