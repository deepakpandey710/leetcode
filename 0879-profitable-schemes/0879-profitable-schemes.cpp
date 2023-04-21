class Solution {
public:
    int mod=1e9+7;
    vector<vector<vector<long>>>dp;
    long f(int i,int cur,int mem,int mn,int n,vector<int>& group, vector<int>& profit){
        if(mem>n)return 0;
        if(i==profit.size()){
            if(cur>=mn)
                return 1;
            return 0;
        }
        if(dp[i][min(cur,mn)][mem]!=-1)return dp[i][min(cur,mn)][mem];
        int nottake=f(i+1,cur,mem,mn,n,group,profit);
        int take= f(i+1,cur+profit[i],mem+group[i],mn,n,group,profit);
        return dp[i][min(cur,mn)][mem]=long(take+nottake)%mod;
        // return take+nottake;    
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m=group.size();
        dp.resize(m,vector<vector<long>>(101,vector<long>(101,-1)));
        return (int)f(0,0,0,minProfit,n,group,profit);
    }
};