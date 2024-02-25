class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            vector<int>cur(i,1);
            for(int j=1;j<i-1;j++){
                cur[j]=ans[i-2][j-1]+ans[i-2][j];
            }
            ans.push_back(cur);
        }
        return ans;
    }
};