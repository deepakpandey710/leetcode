class Solution {
public:
    long long largestPerimeter(vector<int>& num) {
        sort(num.begin(),num.end());
        int n=num.size();
        vector<long>nums(n);
        nums[0]= (long) num[0];
        for(int i=1;i<n;i++){
            nums[i]=num[i]+nums[i-1];
        }
        int i=n-1;
        while(i>1){
            // cout<<"i :"<<nums[i]<<nums[i-1]<<endl;
            if(num[i]<nums[i-1])return nums[i];
            i--;
        }
        return -1;
    }
};