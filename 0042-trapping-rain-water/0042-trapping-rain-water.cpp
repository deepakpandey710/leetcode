class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>suf(n),pre(n);
        suf[0]=height[0];
        pre[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            suf[i]=max(suf[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            pre[i]=max(pre[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            cout<<min(suf[i],pre[i])<<height[i]<<endl;
            ans+=(min(suf[i],pre[i])-height[i]);
        }
        return ans;
    }
};