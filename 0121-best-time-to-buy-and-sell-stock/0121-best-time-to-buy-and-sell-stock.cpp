class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,mn=prices[0];
        for(auto &it:prices){
            mn=min(it,mn);
            ans=max(ans,it-mn);
        }
        return ans;
    }
};