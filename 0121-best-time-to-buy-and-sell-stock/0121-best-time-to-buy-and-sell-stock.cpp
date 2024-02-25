class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,n=prices.size(),cur=prices[0];
        for(int i=0;i<n;i++){
            if(prices[i]>cur){
                ans=max(ans,prices[i]-cur);
            }else{
                cur=min(cur,prices[i]);
            }
        }
        return ans;
    }
};