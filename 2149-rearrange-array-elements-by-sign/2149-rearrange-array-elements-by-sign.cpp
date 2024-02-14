class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size(),i=0,j=0,p=1;
        while(i<n || j<n){
            if(p){  
                while(i<n){
                    if(nums[i]>0){
                       ans.push_back(nums[i]);
                        i++;
                        break;
                    }
                    i++;
                }
            }else{
                while(j<n){
                    if(nums[j]<0){
                       ans.push_back(nums[j]);
                        j++;
                        break;
                    }
                    j++;
                }
            }
            p=!p;
        }
        return ans;
    }
};