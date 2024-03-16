class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mpp;
        int mx=0,sm=0;
        mpp[0]=-1;
        for(int i=0;i<n;i++){
            sm+=(nums[i]==0)?-1:1;
            if(mpp.find(sm)!=mpp.end()){
                mx=max(mx,i-mpp[sm]);
            }else{
                mpp[sm]=i;
            }
        }
        return mx;
    }
};