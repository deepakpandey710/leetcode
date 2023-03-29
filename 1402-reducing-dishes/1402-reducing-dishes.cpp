class Solution {
public:
    int f(int i,vector<int>& s,int cnt,vector<vector<int>>&dp){
        if(i==s.size()){
            return 0;
        }
        if(dp[i][cnt]!=-1)return dp[i][cnt];
        int take=(s[i]*cnt)+f(i+1,s,cnt+1,dp);
        int nottake=f(i+1,s,cnt,dp);
        return dp[i][cnt]=max(take,nottake);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,satisfaction,1,dp);
    }
};