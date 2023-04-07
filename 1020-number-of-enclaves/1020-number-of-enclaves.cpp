class Solution {
public:
    vector<int>dir={-1,0,1,0,-1};
    bool dfs(int i,int j,vector<vector<int>>& grid,int &cnt){
        int n=grid.size(),m=grid[0].size();
        grid[i][j]=0;
        if(i==n-1|| j==m-1||i==0 ||j==0)return false;
        bool f=true;
        for(int k=0;k<4;k++){
            int x=i+dir[k],y=j+dir[k+1];
            if(x<n && y<m && x>=0 && y>=0 && grid[x][y]){
                cnt++;
                
                f=f&dfs(x,y,grid,cnt);
            }
        }
        return f;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                int cnt=1;
                if(grid[i][j] && dfs(i,j,grid,cnt)){
                    ans+=cnt;
                }
            }
        }
        return ans;
    }
};