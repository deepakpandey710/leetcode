class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx=0,cnt=0,n=nums.size(), i=0;
        long long ans=0;
        for(auto &it:nums)mx=max(mx,it);
        for(int j=0;j<n;j++){
            if(nums[j]==mx)cnt++;
            while(cnt>=k){
                if(nums[i++]==mx)cnt--;
            }
            ans+=i;
        }
        return ans;
    }
};