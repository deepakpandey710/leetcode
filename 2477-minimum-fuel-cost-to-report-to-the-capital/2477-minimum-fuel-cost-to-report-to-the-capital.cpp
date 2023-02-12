class Solution {
public:
    long long ans=0;
    long long f(int i,int p,vector<int>adj[],int &s){
        // if(adj[i].size()<=1){
        //     return 1;
        // }
        long long ppl=1;
        for(auto &it:adj[i]){
            if(it!=p){
                ppl+=f(it,i,adj,s);
            }
        }
        if(i!=0)
            ans+=ceil((double)ppl/s);
        return ppl;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        vector<int>adj[n+1];
        for(auto &it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        long long x=f(0,-1,adj,seats);
        return ans;
    }
};