class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int m=tickets[k],ans=0,n=tickets.size();
        if(k==0 && tickets[0]==1)return 1;
        for(int i=0;i<n;i++){
            ans+=i<=k?min(m,tickets[i]):min(m-1,tickets[i]);
        }
        return ans;
    }
};