class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int j,vector<int>& cuts){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mn=INT_MAX;
        for(int k=i;k<=j;k++){
            mn=min(mn,cuts[j+1]-cuts[i-1]+f(i,k-1,cuts)+f(k+1,j,cuts));
        }
        return dp[i][j]=mn;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int c=cuts.size();
        dp.resize(c+1,vector<int>(c+1,-1));
        return f(1,c-2,cuts);
    }
};