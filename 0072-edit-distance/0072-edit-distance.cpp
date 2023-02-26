class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int j,string &s, string &t){
        if(i==0)return j;
        if(j==0)return i;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==t[j-1])
            return dp[i][j]= f(i-1,j-1,s,t);
        return dp[i][j]=1+min(f(i-1,j,s,t),min(f(i,j-1,s,t),f(i-1,j-1,s,t)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return f(n,m,word1,word2);
    }
};