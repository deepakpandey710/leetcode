class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int f =0,ans=0;
        for(auto &it:nums){
            f^=it;
        }
        while(f || k){
            if(f%2!=k%2)ans++;
            f/=2;
            k/=2;
        }
        return ans;
    }
};