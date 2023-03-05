class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>mpp;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        vis[0]=1;
        int cnt=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int x=q.front();
                q.pop();
                if(x==n-1){
                    return cnt;
                }    
                for(auto &j:mpp[arr[x]]){
                    if(!vis[j]){
                        vis[j]=1;
                        q.push(j);
                    }
                }
                mpp[arr[x]].clear();
                if(x+1<n && !vis[x+1]){
                    vis[x+1]=1;
                    q.push(x+1);
                }
                if(x-1>=0 && !vis[x-1]){
                    vis[x-1]=1;
                    q.push(x-1);
                }
            }
            cnt++;
        }
        return cnt;
    }
};