class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int pref=1,tot=1,cntz=0,j=0;
        for(int i=0;i<n;i++){
            tot*=nums[i];
            if(nums[i]==0){
                cntz++;
                j=i;
            }
            
        }
        vector<int>ans(n,0);
        if(cntz>1){
            return ans;
        }
        else if(cntz==1){
            ans[j]=1;
            for(int i=0;i<n;i++){
                if(i!=j){
                    ans[j]*=nums[i];
                }
            }
            return ans;
        }else{
            for(int i=0;i<n;i++){
                ans[i]=pref*(tot/(pref*nums[i]));
                pref*=nums[i];
            }
        }
        return ans;
    }
};