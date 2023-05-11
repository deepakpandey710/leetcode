class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int j,vector<int>& nums1, vector<int>& nums2) {
        if(i==nums1.size()||j==nums2.size())
            return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int nt=max(f(i+1,j,nums1,nums2),f(i,j+1,nums1,nums2));
        int take=0;
        if(nums1[i]==nums2[j]){
            take=1+f(i+1,j+1,nums1,nums2);
        }
        return dp[i][j]=max(nt,take);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(),vector<int>(nums2.size(),-1));
        return f(0,0,nums1,nums2);
    }
};