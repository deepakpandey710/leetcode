class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN,cur=0;
        for(auto &it:nums){
            cur+=it;
            ans=max(ans,cur);
            if(cur<0){
                cur=0;
            }
        }
        return ans;
    }
};