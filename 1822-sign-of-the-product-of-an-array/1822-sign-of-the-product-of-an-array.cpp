class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt=1;
        for(auto &it:nums){
            if(it==0)return 0;
            if(it<0)cnt=-cnt;
        }
        return cnt;
    }
};