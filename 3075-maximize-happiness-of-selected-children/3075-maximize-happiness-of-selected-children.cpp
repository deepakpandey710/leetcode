class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        int n=h.size();
        sort(h.begin(),h.end());
        long long ans =0;
        int cnt=0,i=n-1;
        while(k){
            ans+=max(h[i]-cnt,0);
            cnt++;
            i--;
            k--;
        }
        return ans;
    }
};