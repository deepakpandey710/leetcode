// class Solution {
// public:
//     static bool cmp(const pair<int,int>&p1,const pair<int,int>&p2){
//         if(p1.first!=p2.first){
//             return p1.first>p2.first;
//         }
//         return p1.second>p2.second;
//     }
//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         map<int,int>mpp;
//         // priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
//          auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
//             if (p1.first != p2.first) {
//                 return p1.first > p2.first;
//             }
//             return p1.second > p2.second;
//         };
//         priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

//         sort(meetings.begin(),meetings.end());
//         int i=1;
//         for(auto &it:meetings){
//             if(pq.empty()){
//                 mpp[0]++;
//                 pq.push({it[1],0});
//             }
//             // else if(i<n){
//             //     pq.push({it[1],i}); 
//             //     mpp[i++]++;
//             // }
//             else{
//                 stack<pair<int,int>>st;
//                 int minRoom = INT_MAX,time=0;
//                 while(!pq.empty()){
//                     auto t=pq.top();
//                     pq.pop();
//                     // cout<<t.first<<t.second<<endl;
                    
//                     if(t.first>=1+it[0]){
//                         if(minRoom==INT_MAX){
//                             if(i<n){
//                                 pq.push(t);
//                                 minRoom=i++;
//                                 time=0;
//                             }
//                             else{
//                                 minRoom=t.second;
//                                 time=t.first;
//                             }
//                         }
//                         while(!st.empty()){
//                             pq.push(st.top());
//                             st.pop();
//                         }
//                         break;
//                     }
//                     if(minRoom>t.second){
//                         minRoom=t.second;
//                         time=t.first;
//                     }
//                     st.push(t);
//                 }
                
//                 int delay=max(time-it[0],0);
//                 mpp[minRoom]++;
//                 pq.push({it[1]+delay,minRoom});
//             }
//         }
//         int ans=0,mx=0;
//         for(auto &it:mpp){
//             // cout<<it.first<<it.second<<endl;
//             if(it.second>mx){
//                 ans=it.first;
//                 mx=it.second;
//             }
//         }
//         return ans;
//     }
// };

bool compare(vector<int>& v1, vector<int>& v2) {
    return v1[0] < v2[0];
}
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        /* Sort the meetings based on start_time */
        sort(meetings.begin(), meetings.end(), compare);
        
        /* Create a priority queue for engaged rooms. Each node of PQ will store {current_meeting_ending_time, room_number} */
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> engaged;
        
        /* Create a priority queue for non-engaged rooms. Each node of PQ will store {room_number} */
        priority_queue<int, vector<int>, greater<int>> unused;
        
        /* Frequency map to store the frequency of meetings in each room */
        unordered_map<int, int> freq;
        
        /* Currently all the rooms are mepty */
        for(int i = 0; i < n; i++) {
            unused.push(i);
        }
        
        for(auto x:meetings) {
            int s = x[0], e = x[1];
            
            /* Move the meeting rooms in engaged, with ending_time <= s, to unused */ 
            while(engaged.size() > 0 && engaged.top().first <= s) {
                int room = engaged.top().second;
                engaged.pop();
                
                unused.push(room);
            }
            
            /* If there are multiple empty rooms, choose the one with lower room_number */
            if(unused.size() > 0) 
            {
                int room = unused.top();
                unused.pop();
                
                freq[abs(room)] += 1;
                
                /* Mark the room as engaged */
                engaged.push({e, room});
            }
            /* If there are no empty rooms, wait for the engaged room with nearest ending time to empty */
            else 
            {
                pair<long long, int> topmost = engaged.top();
                engaged.pop();
            
                freq[abs(topmost.second)] += 1;
                
                /* Since duration has to be the same, the newEnd will be sum(end_time_of_the_prev_meeting, duration) */ 
                long long newEnd = topmost.first;
                newEnd += (e - s);
                
                /* Mark the room as engaged */
                engaged.push({newEnd, topmost.second});
            }
        }
        
        /* Find the lowest room_number with maximum frequency */
        int maxi = 0;
        for(int i = 1; i < n; i++) {
            if(freq[i] > freq[maxi])
                maxi = i;
        }
        return maxi;
    }
};