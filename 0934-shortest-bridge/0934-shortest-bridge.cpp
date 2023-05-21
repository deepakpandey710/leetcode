class Solution {
public:
    vector<int>dir={-1,0,1,0,-1};
    void dfs(int i,int j,vector<vector<int>>& grid){
        if( min(i,j)<0 || max(i,j)>=grid.size()||grid[i][j]!=1){
            return;
        }
        grid[i][j]=2;
        for(int k=0;k<4;k++){
            dfs(i+dir[k],j+dir[k+1],grid);
        }
    }
    bool expand(int i,int j,int c,vector<vector<int>>& grid) {
        if( min(i,j)<0 || max(i,j)>=grid.size()){
            return false;
        }
        grid[i][j]=grid[i][j]==0?1+c:grid[i][j];
        return grid[i][j]==1;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int cnt=0;
        for(int i=0; i<n && !cnt; i++){
            for(int j=0; j<n && !cnt; j++){
                if(grid[i][j]){
                    dfs(i,j,grid);
                    cnt=2;
                    break;
                }
            }
        }
        while(cnt){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==cnt){
                        cout<<i<<j<<endl;
                        for(int k=0;k<4;k++){
                            if(expand(i+dir[k],j+dir[k+1],cnt,grid))
                                return cnt-2;
                        }
                    }
                }
            }
            cnt++;
        }
        return cnt-2;
        
    }
};