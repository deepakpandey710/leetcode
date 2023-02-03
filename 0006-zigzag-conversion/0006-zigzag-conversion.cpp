class Solution {
public:
    string convert(string s, int n) {
        if(n==1)return s;
        vector<string>res(n);
        int j=0,k=1;
        for(int i=0;i<s.size();i++){
            res[j]+=s[i];
            j+=k;
            if(j==n-1||j==0){
                k*=-1;
            }
            
        }
        string ans="";
        for(auto &it:res){
            ans+=it;
        }
        return ans;
    }
};