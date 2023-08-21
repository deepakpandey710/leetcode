class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        int i=1,j=0;
        while(i<n){
            if(s[i]==s[j])dp[++i]=++j;
            else if(j==0)++i;
            else j=dp[j];
        }
        return dp[n]&&(dp[n]%(n-dp[n]))==0;
    }
};