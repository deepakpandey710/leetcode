class Solution {
public:
    void merge(int low,int mid,int high,vector<int>& nums){
        if(low>=high)return;
        int l=low,r=mid,k=0;
        vector<int>cur(high-low+1);
        while(l<mid && r<=high){
            if(nums[l]<nums[r]){
                cur[k++]=nums[l++];
            }
            else
                cur[k++]=nums[r++];
        }
        while(l<mid){
            cur[k++]=nums[l++];
        }
        while(r<=high){
            cur[k++]=nums[r++];
        }
        for(int i=0;i<=high-low;i++){
            nums[low+i]=cur[i];
        }
    }
    void divide(int low,int high,vector<int>& nums){
        if(low<high){
            int mid=(low+high)/2;
            divide(low,mid,nums);
            divide(mid+1,high,nums);
            merge(low,mid+1,high,nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        divide(0,nums.size()-1,nums);
        return nums;
    }
};
