class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mpp;
        int mx=0,ans=0;
        for(auto &it:nums){
            mpp[it]++;
        }
        for(auto &it:mpp){
            if(it.second>mx){
                mx=it.second;
                ans=it.second;
            }else if(it.second==mx){
                ans+=it.second;
            }
        }
        return ans;
    }
};