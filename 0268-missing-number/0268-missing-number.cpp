class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),x=n;
        for(int i=0;i<nums.size();i++){
            x^=nums[i]^i;
        }
        return x;
    }
};