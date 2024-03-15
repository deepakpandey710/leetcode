class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int pre=0, ans=0;
        for(auto &it:nums){
            pre+=it;
            int reminder=pre%k;
            if(reminder<0){
                reminder+=k;
            }
            ans+=mpp[reminder]++;
        }
        return ans;
    }
};