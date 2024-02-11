class Solution {
public:
    vector<vector<vector<int>>>dp;
    int f(int i, int j1, int j2,vector<vector<int>>& g){
        if(j1<0 ||j2<0|| j1==g[0].size()|| j2==g[0].size()){
            return 0;
        }
        if(i==g.size()-1){
            if(j1==j2)return g[i][j1];
            return g[i][j1]+g[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int ans=0;
        for(int k=-1;k<2;k++){
            for(int l=-1;l<2;l++){
                if(j1==j2) ans=max(ans,g[i][j1]+f(i+1,j1+k,j2+l,g));
                else ans=max(ans,g[i][j1]+g[i][j2]+f(i+1,j1+k,j2+l,g));
            }
        }
        return dp[i][j1][j2]=ans;
    }
    int cherryPickup(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,g);
    }
};