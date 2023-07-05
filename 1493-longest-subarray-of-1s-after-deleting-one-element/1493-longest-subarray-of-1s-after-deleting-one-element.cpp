class Solution {
public:
    void f(int i,vector<int>& nums,int cnt,int &ans, int t ){
        int n=nums.size();
        while(i<n&&nums[i]==1){
            cnt++;
            i++;
        }
        if(i==n){
            ans=max(ans,cnt);
            return ;
        }
        if(!t){
            f(i+1,nums,cnt,ans,1);
            f(i+1,nums,0,ans,0);
        }
        else{
            ans=max(ans,cnt);
        }
    }
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int i=0;
        while(i<n&&nums[i]==0){
            i++;
        }
        f(i,nums,0,ans,0);
        return ans==n?n-1:ans;
    }
};