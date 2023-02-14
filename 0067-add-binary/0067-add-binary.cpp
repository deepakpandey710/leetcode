class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size()-1,m=b.size()-1,c=0;
        string ans="";
        while(n>=0 && m>=0){
            int x=c+(a[n]-'0')+(b[m]-'0');
            if(x>1){
                ans+=to_string(x%2);
                c=1;
            }
            else{
                ans+=to_string(x);
                c=0;
            }
            n--;
            m--;
        }
        while(n>=0){
            int x=c+(a[n]-'0');
            if(x>1){
                ans+=to_string(x%2);
                c=1;
            }
            else{
                ans+=to_string(x);
                c=0;
            }
            n--;
        }
        while(m>=0){
            int x=c+(b[m]-'0');
            if(x>1){
                ans+=to_string(x%2);
                c=1;
            }
            else{
                ans+=to_string(x);
                c=0;
            }
            m--;
        }
        if(c==1){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};