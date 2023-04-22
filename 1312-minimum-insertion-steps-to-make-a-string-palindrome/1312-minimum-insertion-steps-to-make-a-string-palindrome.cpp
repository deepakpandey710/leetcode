class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int j ,string &s,string &t){
        if(i==-1||j==-1)
            return 0;    
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]= 1+f(i-1,j-1,s,t);
        }
        return dp[i][j]= max(f(i-1,j,s,t),f(i,j-1,s,t));
    }
    int minInsertions(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        dp.resize(n,vector<int>(n,-1));
        return n-f(n-1,n-1,s,t);
    }
};