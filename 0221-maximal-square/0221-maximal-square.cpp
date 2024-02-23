class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')continue;
                // cout<<i<<j<<endl;
                int k=i,l,nc=m;
                while(k<min(n,i+nc-j)){
                    l=j;
                    if(matrix[k][l]=='0'){
                        break;
                    }
                    while(l<nc){
                        if(matrix[k][l]=='0'){
                            nc=l;
                            break;
                        }
                        l++;
                    }
                    k++;
                }
                // cout<<k<<l<<endl;
                ans=max(ans,min(k-i,l-j)*min(k-i,l-j));
                
            }
        }
        return ans;
    }
};