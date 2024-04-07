class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i=0,n=nums.size(),ans=1;
        for(int i=0;i<n;i++){
            int cnt=1;
            for(int j=i+1;j<n;j++){
                if(nums[j]<=nums[j-1]){
                    break;
                }
                cnt++;
            }
            for(int j=i+1;j<n;j++){
                if(nums[j]>=nums[j-1]){
                    break;
                }
                cnt++;
            }
            ans=max(ans,cnt);
        }
        
        
//         if(n<2)return n;
//         while(i<n){
//             while(i+1<n && nums[i]==nums[i+1]){
//                     i++;
//             }
//             int j=i+1;
//             if(j<n && nums[j]>nums[j-1]){
//                 while(j<n && nums[j]>nums[j-1]){
//                     j++;
//                 }
//             }else{
//                 while(j<n && nums[j]<nums[j-1]){
//                     j++;
//                 }
//             }
//             ans=max(ans,j-i);
//             if(j!=n && nums[j]!=nums[j-1])j--;
//             i=j;
//         }
        return ans;
    }
};