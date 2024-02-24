class UnionFind{
    vector<int>parent;
public:
    UnionFind(int n){
        parent.resize(n,0);
        for(int i=1;i<n;i++){
            parent[i]=1+parent[i-1];
        }
    }
    void connect(int a,int b){
        parent[find(b)]=find(a);
    }
    
    int find(int i){
        return parent[i]==i?i:(parent[i]=find(parent[i]));
    }
    
    bool connected(int b){
        return find(0)==find(b);
    }
    
    void reset(int a){
        parent[a]=a;
    }
};

class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2){
        return v1[2]<v2[2];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),cmp);
        UnionFind uf(n);
        uf.connect(0,firstPerson);
        vector<int>ppl,ans;
        for(int i=0,m=meetings.size();i<m;){
            ppl.clear();
            int time=meetings[i][2];
            for(;i<m && time==meetings[i][2];++i){
                uf.connect(meetings[i][0],meetings[i][1]);
                ppl.push_back(meetings[i][0]);
                ppl.push_back(meetings[i][1]);
            }
            for(auto &it:ppl){
                if(!uf.connected(it))uf.reset(it);
            }
        }
        
        for(int i=0;i<n;i++){
            if(uf.connected(i))ans.push_back(i);
        }
        return ans;
    }
    
};