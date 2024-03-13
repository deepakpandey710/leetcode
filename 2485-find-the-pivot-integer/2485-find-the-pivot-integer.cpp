class Solution {
public:
    int pivotInteger(int n) {
        int tot=(n*(n+1))/2;
        int cur=0;
        while(cur<=tot){
            cur+=n;
            if(cur==tot)return n;
            tot-=n;
            n--;
        }
        return -1;
    }
};