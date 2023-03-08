class Solution {
public:
    bool check(vector<int>&piles,int mid,int h){
        int cur=0;
        for(auto &it:piles){
            if(it%mid==0){
                cur+=it/mid;
            }
            else{
                cur+=it/mid+1;
            }
            if(cur>h){
                return false;
            }
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=1e9,low=1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(piles,mid,h)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return high;
    }
};