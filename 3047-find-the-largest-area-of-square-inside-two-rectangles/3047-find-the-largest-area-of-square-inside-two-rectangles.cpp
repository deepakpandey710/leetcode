class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& b, vector<vector<int>>& t) {
        int n=b.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int min_x= max(b[i][0],b[j][0]);
                int max_x= min(t[i][0],t[j][0]);
                int min_y= max(b[i][1],b[j][1]);
                int max_y= min(t[i][1],t[j][1]);
                if(min_x<max_x && min_y<max_y){
                    long long side=min(max_x-min_x,max_y-min_y);
                    ans=max(ans,side*side);
                }
            }
        }
        return ans;
    }
};