class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            int l=i+1,m=j-1;
            while(l<j && s[i]==s[l]){
                l++;
            }
            while(l<m && s[j]==s[m]){
                m--;
            }
            if(s[i]==s[j]){
                i=l;
                j=m;
            }else 
                break;
        }
        return max(j-i+1,0);
    }
};