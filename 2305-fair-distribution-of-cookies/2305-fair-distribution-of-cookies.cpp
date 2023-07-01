class Solution {
public:
    void f(int i,vector<int>& cookies, vector<int>&temp, int &ans,int &k){
        if(i==cookies.size()){
            int mx=INT_MIN;
            for(int j=0;j<k;j++){
                mx=max(mx,temp[j]);
            }
            ans=min(ans,mx);
            return;
        }
        for(int j=0;j<k;j++){
            temp[j]+=cookies[i];
            f(i+1,cookies,temp,ans,k);
            temp[j]-=cookies[i];
        } 
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int ans=INT_MAX;
        vector<int>temp(k,0);
        f(0,cookies,temp,ans,k);
        return ans;
        
    }
};