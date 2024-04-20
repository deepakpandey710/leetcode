class Solution {
public:
    void f(int i, int j,vector<vector<int>>& land, vector<int> &res ){
        if(i>=land.size() || j>=land[0].size() || !land[i][j])return ;
        res[0]=min(res[0],i);
        res[1]=min(res[1],j);
        res[2]=max(res[2],i);
        res[3]=max(res[3],j);
        land[i][j]=0;
        f(i+1,j, land,res);
        f(i, j+1, land, res);
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        int n=land.size(),m=land[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<i<<" "<<j<<endl;
                if(land[i][j]){
                    vector<int>res={i,j,i,j};
                    f(i,j,land,res);
                    ans.push_back(res);
                }
            }
        }
        
        return ans;
    }
};