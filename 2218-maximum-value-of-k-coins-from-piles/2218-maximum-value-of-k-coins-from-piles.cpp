class Solution {
public:
  
    vector<vector<int>>dp;
     int f(int i,vector<vector<int>>& piles, int k){
         if(i>=piles.size()){
           return 0;
         }
         if(dp[i][k]!=-1)return dp[i][k];
         int mx=0;
         mx=f(i+1,piles,k);
         for(int j=0;j<piles[i].size();j++){
             if(j<k){
                 mx=max(mx,piles[i][j]+f(i+1,piles,k-j-1));
             }else
                 break;
         }
         return dp[i][k]=mx;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        dp.resize(n,vector<int>(k+1,-1));
        for(int i=0;i<n;i++){
            for(int j=1;j<piles[i].size();j++){
                piles[i][j]=piles[i][j-1]+piles[i][j];
            }
        }
        return f(0,piles,k);
    }
};