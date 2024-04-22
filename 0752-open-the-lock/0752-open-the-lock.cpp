class Solution {
public:
//     void f(set<string>& st,string cur, string &target,int cnt, int &ans){
//         if(cur==target){
//             ans=min(ans,cnt);
//             return;
//         }
//         if(st.find(cur)!=st.end()){
//             return;
//         }
        
//         for(int i=0;i<4;i++){
//             if(cur[i]-'0'<9){
//                 f(st,cur,target,cnt,ans);
//                 cur[i]+=1;
//                 f(st,cur,target,cnt+1,ans);
//             }
//             // if(target[i]-'0'<=9){
//             //     target[i]+=1;
//             //     f(st,target,cnt+1,ans);
//             //     target[i]-=1;
//             // }
//             // if(target[i]-'0'>0){
//             //     target[i]-=1;
//             //     f(st,target,cnt+1,ans);
//             //     target[i]+=1;
//             // }
//         }
        
//     }
//     int openLock(vector<string>& deadends, string target) {
//         int ans=INT_MAX;
//         set<string>st(deadends.begin(),deadends.end());
//         f(st,"0000",target,0,ans);
//         return ans==INT_MAX?-1:ans;
//     }
    
     int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        if (deadSet.count("0000")) return -1;
        queue<string> q({"0000"});
        for (int steps = 0; !q.empty(); ++steps) {
            for (int i = q.size(); i > 0; --i) {
                auto curr = q.front(); q.pop();
                if (curr == target) return steps;
                for (auto nei : neighbors(curr)) {
                    if (deadSet.count(nei)) continue;
                    deadSet.insert(nei); // Marked as visited
                    q.push(nei);
                }
            }
        }
        return -1;
    }
    vector<string> neighbors(const string& code) {
        vector<string> result;
        for (int i = 0; i < 4; i++) {
            for (int diff = -1; diff <= 1; diff += 2) {
                string nei = code;
                nei[i] = (nei[i] - '0' + diff + 10) % 10 + '0';
                result.push_back(nei);
            }
        }
        return result;
    }
};