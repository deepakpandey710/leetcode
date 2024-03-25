class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int index=abs(nums[i])-1;
            int val=nums[index];
            if(val<0){
                return index+1;
            }
            else{
                nums[index]= -1*nums[index];
            }
        }
            return nums.size();
    }
};
