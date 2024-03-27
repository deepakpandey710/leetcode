class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0, i=0,j=0,n=nums.size(),p=1;
        while(i<n){
            p*=nums[i];
            while(j<=i && p>=k){
                p/=nums[j];
                j++;
            }
            if(p<k){
                ans+=i-j+1;
            }
            i++;
        }
        return ans;
    }
};