class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ne) {
        int n=in.size(),i=0;
        vector<vector<int>>ans;
        while(i<n && ne[0]>in[i][0]&&ne[0]>in[i][1]){
            ans.push_back(in[i]);
            i++;
        }
        if(i==n){
            in.push_back(ne);
            cout<<"y";
            return in;
        }
        int j;
        if(ne[0]<in[i][0] && ne[1]<in[i][0]){
            ans.push_back(ne);
            while(i<n){
                ans.push_back(in[i++]);
            }
        }
        else{
            in[i]={min(in[i][0],ne[0]),max(in[i][1],ne[1])};
            ans.push_back(in[i]);
            j=i+1;
            while(j<n && in[i][1]>=in[j][0]){
                ans[i][1]=max(in[i][1],in[j][1]);
                // ans.push_back(in[j]);
                j++;
            }
            while(j<n){
                ans.push_back(in[j++]);
            }
        }
        // i++;        
        return ans;
    }
};