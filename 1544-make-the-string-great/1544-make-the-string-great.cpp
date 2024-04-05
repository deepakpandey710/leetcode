class Solution {
public:
    string makeGood(string s) {
        string ans="";
        int i=-1,n=s.size();
        for(int j=0;j<n;j++){
            while(j<n && i>=0 && abs(ans[i]-s[j])==32){
                j++;
                ans.pop_back();
                i--;
            }
            if(j<n){
                ans+=s[j];
                i++;
            }
        }
        return ans;
    }
};