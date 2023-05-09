class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),r1=0,r2=n-1,c1=0,c2=m-1,i=0,j=0;
        vector<int>ans;
        while(r1<=r2 && c1<=c2){
            i=c1;j=c2;
            while(i<=j){
                ans.push_back(matrix[r1][i]);
                i++;
            }
            r1++;
            i=r1;j=r2;
            while(i<=j){
                ans.push_back(matrix[i][c2]);
                i++;
            }
            c2--;
            if (r1 <= r2) {
            i=c1;j=c2;
            while(i<=j){
                ans.push_back(matrix[r2][j]);
                j--;
            }
            r2--;
            }
            if (c1 <= c2) {
            i=r1;j=r2;
            while(i<=j){
                ans.push_back(matrix[j][c1]);
                j--;
            }
            c1++;
            }
            cout<<r1<<"  "<<r2<<"  "<<c1<<"  "<<c2<<endl;
        }
        return ans;
    }
};