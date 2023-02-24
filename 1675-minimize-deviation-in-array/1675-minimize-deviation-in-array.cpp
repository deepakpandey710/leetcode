class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int mn=INT_MAX,mx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2)
                nums[i]*=2;
            mx=max(mx,nums[i]);
            mn=min(mn,nums[i]);
        }
        int ans=mx-mn;
        for(auto &it:nums){
            pq.push(it);
        }
        while((pq.top()%2)==0){
            int x=pq.top();
            pq.pop();
            ans=min(ans,x-mn);
            x/=2;
            mn=min(mn,x);
            pq.push(x);
        }
        
        ans=min(ans,pq.top()-mn);
        return ans;
    }
};