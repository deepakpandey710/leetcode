class Graph {
public:
    vector<vector<vector<int>>>adj;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto &it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        this->n=n;
    }
    
    void addEdge(vector<int> it) {
        adj[it[0]].push_back({it[1],it[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[node1]=0;
        pq.push({0,node1});
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            for(auto &it:adj[t[1]]){
                if(dist[it[0]]>t[0]+it[1]){
                    pq.push({t[0]+it[1],it[0]});
                    dist[it[0]]=t[0]+it[1];
                }
            }
        }
        return dist[node2]==INT_MAX?-1:dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */