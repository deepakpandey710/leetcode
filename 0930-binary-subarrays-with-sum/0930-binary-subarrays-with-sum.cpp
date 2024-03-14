class Solution {
public:
    int f(int i, int started, int &goal,int cur, vector<int>&nums){
        if(cur==0)return 1;
        if(i==nums.size()){
            return 0;
        }
        int ans=0;
        if(started){
            ans+=f(i,false,goal,goal,nums);
        }
        ans+=f(i+1,true,goal,cur-nums[i],nums);
        if(!started){
            ans+=f(i+1,false,goal,goal,nums);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       unordered_map<int,int>mpp({{0,1}});
        int pre_sum=0,res=0;
        for(auto &it:nums){
            pre_sum+=it;
            res+=mpp[pre_sum-goal];
            mpp[pre_sum]++;
        }
        return res;
    }
};