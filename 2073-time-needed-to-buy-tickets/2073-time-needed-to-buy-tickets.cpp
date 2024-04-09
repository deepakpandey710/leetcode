class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int m=tickets[k],ans=0,n=tickets.size();
        while(true){
            for(int i=0;i<n;i++){
                if(tickets[k]==0)
                    return ans;
                if(tickets[i]!=0){
                    tickets[i]--;
                    ans++;
                }
            }
        }
        return 1;
    }
};