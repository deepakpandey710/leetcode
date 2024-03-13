class Solution {
public:
    vector<vector<vector<long long>>>dp;
    long long f(int i, long long k,int started,vector<int>& nums){
        if(k==0){
            return 0;
        }
        if(i==nums.size()){
            if(k == 1 && started) return 0;
            return -1e15;
        }
        if(dp[i][started][k]!=-1e15)return dp[i][started][k];
        long long ans=-1e15;
        if(started){
            ans=f(i,k-1,false,nums);
        }
        ans=max(ans,(k%2==1?1:-1)*k*nums[i]+f(i+1,k,true,nums));
        if(!started){
            ans=max(ans,f(i+1,k,false,nums));
        }
        return dp[i][started][k]= ans;
    }
    long long maximumStrength(vector<int>& nums, int k) {
        int n=nums.size();
        dp.resize(n,vector<vector<long long>>(2,vector<long long>(k+1,-1e15)));
        return f(0,k,0,nums);
    }
};