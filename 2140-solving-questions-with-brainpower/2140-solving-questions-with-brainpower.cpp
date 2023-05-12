class Solution {
public:
    vector<long long>dp;
    long long f(int i,vector<vector<int>>& questions){
        if(i>=questions.size())
            return 0;
        if(dp[i]!=-1)return dp[i];
        long long nt=f(i+1,questions);
        long long take=questions[i][0]+f(i+1+questions[i][1],questions);
        return dp[i]=max(take,nt);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        dp.resize(questions.size(),-1);
        return f(0,questions);
    }
};