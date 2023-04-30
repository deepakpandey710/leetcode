class DSU{
    vector<int>parentA,parentB;
    public:
    DSU(int n){
        parentA.resize(n+1);
        parentB.resize(n+1);
        for(int i=1;i<=n;i++){
            parentA[i]=i;
            parentB[i]=i;
        }
    }
    int findParentA(int n){
        if(n==parentA[n]){
            return n;
        }
        return parentA[n]=findParentA(parentA[n]);
    }
    int findParentB(int n){
        if(n==parentB[n]){
            return n;
        }
        return parentB[n]=findParentB(parentB[n]);
    }
    bool makeUnionA(int n1,int n2){
        int p1=findParentA(n1),p2=findParentA(n2);
        if(p1==p2)return false;
        parentA[p1]=p2;
        return true;
    }
    bool makeUnionB(int n1,int n2){
        int p1=findParentB(n1),p2=findParentB(n2);
        if(p1==p2)return false;
        parentB[p1]=p2;
        return true;
    }
    
};
class Solution {
public:
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU ds(n);
        int cnt=0,e1=0,e2=0;
        sort(edges.begin(),edges.end(),[&](const vector<int>&v1,const vector<int>&v2){
            return v2[0]<v1[0];
        });
        for(auto &it:edges){
            int n1=it[1],n2=it[2];
            if(it[0]==1){
                if(ds.makeUnionA(n1,n2)){
                    e1++;
                }else{
                    cnt++;
                }
            }
            else if(it[0]==2){
                if(ds.makeUnionB(n1,n2)){
                    e2++;
                }else{
                    cnt++;
                }
            }else{
                if(ds.makeUnionA(n1,n2) && ds.makeUnionB(n1,n2)){
                    e1++;e2++;
                }else{
                    cnt++;
                }
            }
        }
        cout<<cnt<<e1<<e2<<endl;
        if(e1!=n-1||e2!=n-1)return -1;
        return cnt;
    }
};
