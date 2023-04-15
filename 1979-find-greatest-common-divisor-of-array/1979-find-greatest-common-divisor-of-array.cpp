class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn=nums[0],mx=nums[0];
        for(auto &it:nums){
            mn=min(mn,it);
            mx=max(mx,it);
        }
        return __gcd(mn,mx);
    }
};