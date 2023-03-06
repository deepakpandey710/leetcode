class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=1,i=0;
        while(i<arr.size()){
            while(arr[i]!=n){
                if(k==1)return n;
                k--;
                n++;
            }
            n=arr[i]+1;
            i++;
        }
        return n+k-1;
    }
};