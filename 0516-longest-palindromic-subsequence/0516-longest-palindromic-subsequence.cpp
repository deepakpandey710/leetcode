class Solution {
public:
    
    int lcs(int i, int j, string &s, string &t,vector<vector<int>>&dp){
        if(i==s.size()|| j==t.size()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=1+lcs(i+1,j+1,s,t,dp);
        }else{
            return dp[i][j]=max(lcs(i,j+1,s,t,dp),lcs(i+1,j,s,t,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        // int n=s.size();
        // vector<int>dp(n,-1);
        // string t="";
        // return f(0,s,t,dp);
         string s2="";
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            s2+=s[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return lcs(0,0,s,s2,dp);
        
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         if(s[i-1]==s2[j-1]){
        //             dp[i][j]=1+dp[i-1][j-1];
        //         }
        //         else{
        //             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[n][n];
    }
};