class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int m=fb.size(),p=0;
        for(int i=0;i<m;i++){
            if(p==0 && fb[i]==0 &&(i==m-1||fb[i+1]==0)){
                n--;
                p=1;
            }else if(fb[i]==0){
                p=0;
            }
            if(fb[i]==1)p=1;
            cout<<i<<"   "<<n<<endl;
            if(n==0)return true;
        }
        return n<=0;
    }
};