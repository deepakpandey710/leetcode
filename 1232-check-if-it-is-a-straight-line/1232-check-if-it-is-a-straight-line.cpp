class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int x1=c[0][0],y1=c[0][1],x2=c[1][0],y2=c[1][1];
        int n=c.size();
        float m=y1==y2?INT_MAX:(float)(x2-x1)/(float)(y2-y1);
        for(int i=2;i<n;i++){
            x2=c[i][0],y2=c[i][1];
            float l=y1==y2?INT_MAX:(float)(x2-x1)/(float)(y2-y1);
            if(m!=l)return false;
        }
        return true;
    }
};