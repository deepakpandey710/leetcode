class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int>mpp;
        int i=0,n=nums.size(),ans=0;
        for(int j=0;j<n;j++){
            mpp[nums[j]]++;
            while(mpp[nums[j]]>k){
                mpp[nums[i++]]--;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};