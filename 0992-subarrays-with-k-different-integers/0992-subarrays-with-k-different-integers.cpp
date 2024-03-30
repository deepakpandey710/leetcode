class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       int x=atMostK(nums,k-1),y=atMostK(nums,k);
        cout<<x<<"  "<<y<<endl;
        return y-x;
    }
    
    
    int atMostK(vector<int>& A, int K) {
        int i = 0, res = 0;
        unordered_map<int, int> count;
        for (int j = 0; j < A.size(); ++j) {
            if (!count[A[j]]++) K--;
            while (K < 0) {
                if (!--count[A[i]]) K++;
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
    
//     int atMostK(vector<int>& nums, int k) {
//         map<int,int>mpp;
//         int i=0,n=nums.size(),ans=0,cnt=0;
//         for(int j=0;j<n;j++){
//             if(!mpp[nums[j]]++)
//                 cnt++;
//             while(cnt>=k){
//                if(--mpp[nums[i]]){
//                    cnt-=mpp[nums[i]]==0?0:1;;
//                }
//                 i++;
//             }
//             ans+=j-i+1;
//         }
//         return ans;
//     }
};