class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>>v;
        int n=score.size();
        for(int i=0;i<n;i++){
            v.push_back({score[i],i});
        }
        vector<string>ans(n);
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(i==n-1){
                ans[v[i].second]="Gold Medal";
            }
            else if(i==n-2){
                ans[v[i].second]="Silver Medal";
            }
            else if(i==n-3){
                ans[v[i].second]="Bronze Medal";
            }
            else{
                ans[v[i].second]=to_string(n-i);
            }
        }
        return ans;
    }
};