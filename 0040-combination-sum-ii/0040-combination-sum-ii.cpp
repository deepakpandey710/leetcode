class Solution {
public:
    vector<vector<int>>ans;
    void f(int i,int t,vector<int>& c,vector<int>& cur){
        if(t==0){
            ans.push_back(cur);
            return;
        }
        if(i==c.size()){
            return;
        }
        for(int j=i;j<c.size();j++){
            if(i!=j && c[j]==c[j-1])continue;
            if(t<c[j])break;
            cur.push_back(c[j]);
            f(j+1,t-c[j],c,cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>cur;
        sort(candidates.begin(),candidates.end());
        f(0,target,candidates,cur);
        return ans;
    }
};