class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0, i=0,j=0,n=nums.size(),p=1,cnt=0;
        while(i<n){
            p*=nums[i];
            cnt++;
            while(j<=i && p>=k){
                p/=nums[j];
                j++;
                cnt--;
            }
            if(p<k){
                ans+=cnt;
            }
            cout<<ans<<" "<<cnt<<endl;
            i++;
        }
        return ans;
    }
};