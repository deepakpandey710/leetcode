class Solution {
public:
    int dfs(int i,unordered_map<int,vector<int>>&mpp,vector<int>& time){
        int t=time[i],mx=0;
        for(auto &it:mpp[i]){
            mx=max(mx,dfs(it,mpp,time));
        }
        return mx+t;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& time) {
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[manager[i]].push_back(i);
        }
        return dfs(headID,mpp,time);
    }
};