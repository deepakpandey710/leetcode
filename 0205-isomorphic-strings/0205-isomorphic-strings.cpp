class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mpp;
        map<char,char> mppp;
        int n=s.size();
        for(int i=0;i<n;i++){
            if((mpp.find(s[i])!=mpp.end() && mpp[s[i]]!=t[i]) ||(mppp.find(t[i])!=mppp.end() && mppp[t[i]]!=s[i]))
                return 0;
            mpp[s[i]]=t[i];
            mppp[t[i]]=s[i];
        }
        return 1;
    }
};