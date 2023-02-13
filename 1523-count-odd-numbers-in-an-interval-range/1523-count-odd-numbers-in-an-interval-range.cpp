class Solution {
public:
    int countOdds(int low, int high) {
        if(low==high){
            return low%2;
        }
        int d=high-low-1;
        if(low%2 && high%2){
            return (d/2)+2;
        }
        return (d/2)+1;
    }
};