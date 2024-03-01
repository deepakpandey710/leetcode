class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt=0;
        for(auto &ch:s){
            cnt+=ch-'0';
        }
        int n=s.size();
        string ans(n,'0');
        int i=0;
        while(cnt-1){
            ans[i]='1';
            i++;
            cnt--;
        }
        ans[n-1]='1';
        return ans;
    }
};