class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size(),m=n-1;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=mat[i][i];
            ans+=mat[i][m--];
        }
        if(n%2)
            ans-=mat[n/2][n/2];
        return ans;
    }
};