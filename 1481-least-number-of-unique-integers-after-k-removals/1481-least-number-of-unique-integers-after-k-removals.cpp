class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mpp;
        for(auto &it:arr){
            mpp[it]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto &it:mpp){
            pq.push({it.second,it.first});
        }
        while(k>0){
            auto it=pq.top();
            pq.pop();
            mpp[it.second]--;
            if(mpp[it.second]==0){
                mpp.erase(it.second);
            }else{
                pq.push({it.first-1,it.second});
            }
            k--;
        }
        return mpp.size();
    }
};