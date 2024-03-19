class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>d(26,0);
        for(auto &ch:tasks){
            d[ch-'A']++;
        }
        sort(d.begin(),d.end());
        int ans=(d[25]-1)*n+d[25];
        int k=(d[25]-1)*n;
        for(int i=24;i>=0;i--){
            if(d[i]==d[25]){
                ans++;
                k++;
            }
            k-=d[i];
        }
        if(k<0)ans+=(-1*k);
        return ans;
    }
};