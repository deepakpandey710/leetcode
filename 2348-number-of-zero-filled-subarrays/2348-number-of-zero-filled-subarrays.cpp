class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0,cnt=0;
        for(auto &it:nums){
            if(it==0){
                cnt++;
            }else{
                if(cnt%2==0)
                    ans+=(cnt/2)*(cnt+1);
                else
                    ans+=(cnt)*(cnt+1)/2;
                cnt=0;
            }
        }
        if(cnt){
            ans+=(cnt*(cnt+1))/2;
        }
        return ans;
    }
    
};