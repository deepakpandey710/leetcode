class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++) {
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());
        int i = 0;
        priority_queue<int> maximizeCapital;
        while (k--) {
          
            while (i < n && projects[i].first <= w) {
                maximizeCapital.push(projects[i].second);
                i++;
            }
            if (maximizeCapital.empty())
                break;
            w += maximizeCapital.top();
            maximizeCapital.pop();
        }
        return w;
        
        
        //         priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
//         int n=profits.size();
//         int cur=w;
//         vector<vector<int>>v;
//         for(int i=0;i<n;i++){
//             v.push_back({capital[i],profits[i]});
//         }
//         sort(v.begin(),v.end());
//         for(int i=0;i<n;i++){
//             if(v[i][0]<=cur){
//                 pq.push({profits[i],i});
//                 cur+=profits[i];
//                 if(pq.size()>k){
//                     auto f=pq.top();
//                     pq.pop();
//                     cur-=f[0];
//                 }
//             }
            
//         }
//         return cur;
    }
};