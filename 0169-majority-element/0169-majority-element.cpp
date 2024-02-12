class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0, mj=nums[0], n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt==0||nums[i]==mj){
                cnt++;
                mj=nums[i];
            }else{
                cnt--;
            }
        }
        return mj;
    }
};