class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        ///////////using multiset////////
        set<pair<int,int>>mpp;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    mpp.insert({i,j});
                }
            }
        }
        for(auto i: mpp){
            for(int j=0;j<row;j++){
                matrix[j][i.second]=0;
            }
            for(int j=0;j<col;j++){
                matrix[i.first][j]=0;
            }
        }
        
    }
};