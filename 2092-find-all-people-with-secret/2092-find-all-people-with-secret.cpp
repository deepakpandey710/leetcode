class Solution {
public:
//     static bool cmp(vector<int>&v1,vector<int>&v2){
//         return v1[2]<v2[2];
//     }
//     vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
//         sort(meetings.begin(),meetings.end(),cmp);
//         set<int>st({0,firstPerson});
//         for(auto &it:meetings){
//             if(st.find(it[0])!=st.end() || st.find(it[1])!=st.end()){
//                 st.insert(it[0]);
//                 st.insert(it[1]);
//             }
//         }
//         vector<int>ans(st.begin(),st.end());
//         return ans;
        
//     }
    

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,map<int,vector<int>>>mpp;
        for(auto &it:meetings){
            mpp[it[0]][it[2]].push_back(it[1]);
            mpp[it[1]][it[2]].push_back(it[0]);
        }
        queue<vector<int>>q;
        q.push({firstPerson,0});
        q.push({0,0});
        set<int>st({0,firstPerson});
        vector<int>vis(n,INT_MAX);
        vis[0]=0;
        vis[firstPerson]=0;
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            for(auto &time:mpp[f[0]]){
                if(time.first>=f[1]){
                    for(auto &it:time.second){
                        if(vis[it]>time.first){
                            vis[it]=time.first;
                            q.push({it,time.first});
                            st.insert(it);
                        }
                    }
                }
            }
        }
        vector<int>ans(st.begin(),st.end());
        return ans;
        
    }
};