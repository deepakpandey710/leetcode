class Solution {
public:
    
    bool dfs(int i,int j,vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        if(i==n-1 && j==m-1){
            return true;
        }
        if(i>=n ||j>=m || grid[i][j]==0)return false;    
        grid[i][j]=0;
        return dfs(i+1,j,grid)|| dfs(i,j+1,grid);
        
        
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        
        if(!dfs(0,0,grid)){
            cout<<"y"<<endl;
            return true;
        }
        grid[0][0]=1;
        return !dfs(0,0,grid);
    }
};