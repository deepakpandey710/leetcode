class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size(),i=0,j=0,p=1;
        while(i<n || j<n){
            if(p){  
                while(i<n && nums[i]<0)i++;
                if(i<n)ans.push_back(nums[i]);
                i++;
            }else{
                while(j<n && nums[j]>0)j++;
                if(j<n)ans.push_back(nums[j]);
                j++;
            }
            p=!p;
        }
        return ans;
    }
};