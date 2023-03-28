class Solution {
public:
    int f(int i,vector<int>& days, vector<int>& costs,vector<int>&dp){
        if(i>=days.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int one=costs[0]+f(i+1,days,costs,dp);
        int seven=1e8,month=1e8;
        int j=lower_bound(days.begin(),days.end(),days[i]+7)-days.begin();
        int k=lower_bound(days.begin(),days.end(),days[i]+30)-days.begin();
        seven=costs[1]+f(j,days,costs,dp);
        month=costs[2]+f(k,days,costs,dp);
        return dp[i]= min({one,seven,month});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n,-1);
        return f(0,days,costs,dp);
    }
};