class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        int cnt=1;
        int r1=0,r2=n-1,c1=0,c2=n-1,i=0,j=0;
        while(r1<=r2 && c1<=c2){
            i=c1;j=c2;
            while(i<=j){
                ans[r1][i]=cnt;
                i++;
                cnt++;
            }
            r1++;
            i=r1;j=r2;
            while(i<=j){
                ans[i][c2]=cnt;
                i++;
                cnt++;
            }
            c2--;
            if(r1<=r2){
                i=c2;j=c1;
                while(i>=j){
                    ans[r2][i]=cnt;
                    cnt++;
                    i--;
                }
                r2--;
            }
            if(c1<=c2){
                i=r2;j=r1;
                while(i>=j){
                    ans[i][c1]=cnt;
                    cnt++;
                    i--;
                }
                c1++;
            }
        }
        return ans;
    }
};