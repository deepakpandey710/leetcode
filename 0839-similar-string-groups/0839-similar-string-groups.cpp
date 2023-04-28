class Solution {
public:
    
    // int numSimilarGroups(vector<string>& strs) {
    //     int n=strs.size(),m=strs[0].size();
    //     vector<int>parent(n,-1);
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(parent[j]!=-1)continue;
    //             int k=0;
    //             int cnt=0;
    //             while(k<m){
    //                 if(strs[i][k]!=strs[j][k]){
    //                     cnt++;
    //                 }
    //                 if(cnt>2){
    //                     break;
    //                 }
    //                 k++;
    //             }
    //             if(cnt<=2){
    //                 parent[j]=i;
    //             }
    //         }
    //         if(parent[i]==-1)
    //             parent[i]=i;
    //     }
    //     int cnt=0;
    //     for(int i=0;i<n;i++){
    //         if(parent[i]==i)cnt++;
    //     }
    //     return cnt;
    // }
    
class disjoint_set {
    vector<int> v;
    int sz;
public:
    disjoint_set(int n) {
        makeset(n);
    }

    void makeset(int n) {
        v.resize(n);
        iota(v.begin(), v.end(), 0);
        sz = n;
    }

    int find(int i) {
        if (i != v[i])
            v[i] = find(v[i]);
        return v[i];
    }
    
    void join(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri != rj) {
            v[ri] = rj;
            sz--;
        }
    }
    
    int size() {
        return sz;
    }
};    
    
    
    
    
     int numSimilarGroups(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size();
        disjoint_set ds(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k=0;
                int cnt=0;
                while(k<m){
                    if(strs[i][k]!=strs[j][k]){
                        cnt++;
                    }
                    if(cnt>2){
                        break;
                    }
                    k++;
                }
                if(cnt<=2){
                    ds.join(i,j);
                }
            }
        }
        return ds.size();
    }
};
