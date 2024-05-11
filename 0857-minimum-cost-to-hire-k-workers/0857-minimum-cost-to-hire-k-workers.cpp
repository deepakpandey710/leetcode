class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        vector<vector<double>>v;
        for(int i=0;i<q.size();i++){
            v.push_back({(double)w[i]/q[i],(double)q[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int>minh;
        double res=DBL_MAX,sm=0;
        for(auto it:v){
            sm+=it[1];
            minh.push(it[1]);
            if(minh.size() > k ){
                sm-=minh.top();
                minh.pop();
            }
            if(minh.size()==k){
                res=min(res,sm*it[0]);
            }
        }
        
        return res;
    }
};