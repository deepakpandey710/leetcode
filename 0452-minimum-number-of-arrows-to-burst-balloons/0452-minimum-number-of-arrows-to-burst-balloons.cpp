class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int p;
        p=points[0][1];
        int j=1;
        int n=points.size();
        for(int i=1;i<n;i++){
            if(points[i][0]<=p){
                p=min(p,points[i][1]);
            }
            else{
                p=points[i][1];
                j++;
            }
        }
        return j;
    }
};