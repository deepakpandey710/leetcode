class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        if(k==1||k==n)return 0;
        vector<int>d;
        for(int i=0;i<n-1;i++){
            d.push_back(weights[i]+weights[i+1]);
        }
        sort(d.begin(),d.end());
        long long mx=0,mn=0;
        for(int i=0;i<k-1;i++){
            mn+=d[i];
            mx+=d[n-2-i];
        }
        return mx-mn;
    }
};