class Solution {
public:
    int trailingZeroes(int n) {
        if(n<=1)return 0;
        int twos=0,fives=0;
        for(int i=1;i<=n;i++){
            int j=i;
            while(j){
                if(j%2==0){
                    twos++;
                    j/=2;
                }else if(j%5==0){
                    fives++;
                    j/=5;
                }else 
                    break;
            }
        }
        return min(twos,fives);
    }
    
};