class Solution {
public:
    // int f(int i,int mn,int mx,vector<int>& nums, int target){
    //     if(i==nums.size()){
    //         if(mn!=INT_MAX && (mn+mx)<=target)
    //             return 1;
    //         return 0;
    //     }
    //     if(dp[i]!=-1)return dp[i];
    //     int nt=f(i+1,mn,mx,nums,target);
    //     mn=min(mn,nums[i]);
    //     mx=max(mx,nums[i]);
    //     int t=f(i+1,mn,mx,nums,target);
    //     // return dp[i]=t+nt;
    //     return t+nt;
    // }
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size(),mod=1e9+7;
        int ans=0;
        sort(nums.begin(),nums.end());
        vector<int>pow(n,1);
        for(int i=1;i<n;i++){
            pow[i]=(pow[i-1]*2)%mod;
        }
        int i=0,j=n-1;
        
        while(i<=j){
            if((nums[i]+nums[j])>target){
                j--;
            }
            else{
                ans=(ans+pow[j-i])%mod;
                i++;
            }
        }
        return  ans;
        
    }
};