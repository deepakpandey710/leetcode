class Graph {
public:
    vector<vector<vector<int>>>adj;
    vector<vector<int>>dist;
    int m=0;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto &it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        m=n;
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(m,INT_MAX);
        dist[node1]=0;
        pq.push({0,node1});
        while(!pq.empty()){
            int d=pq.top().first;
            int prev=pq.top().second;
            pq.pop();
            for(auto &it:adj[prev]){
                int next=it[0];
                int nextd=it[1];
                if(dist[next]>nextd+d){
                    dist[next]=dist[prev]+nextd;
                    pq.push({dist[next],next});
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