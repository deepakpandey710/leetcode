class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt=1,n=nums.size();
        if(n==1)return 0;
        int mxj=nums[0];
        // for(int i=1;i<n;i++){
        //     if(mxj>=n-1){
        //         return cnt;
        //     }
        //     if(mxj<i+nums[i]){
        //         mxj=i+nums[i];
        //         cnt++;
        //     }
        // }
        
        int i=1;
        while(i<n){
            int mx=mxj;
            if(mx>=n-1){
                return cnt;
            }
            while(i<n&&i<=mxj){
                mx=max(mx,i+nums[i]);
                i++;
                if(mx>=n-1){
                    break;
                }
            }
            cnt++;
            if(mx>=n-1){
                return cnt;
            }
            mxj=mx;
        }
        return cnt;
    }
};