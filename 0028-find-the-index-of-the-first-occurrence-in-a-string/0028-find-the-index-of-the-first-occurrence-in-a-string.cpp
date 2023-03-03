class Solution {
public:

    int strStr(string h, string ne) {
        int n=h.size(),m=ne.size();
        if(n<m)return -1;
        string s=h.substr(0,m);
        if(s==ne){
            return 0;
        }
        for(int i=m;i<n;i++){
            s.erase(0,1);
            s+=h[i];
            if(s==ne){
                return i-m+1;
            }
        }
        return -1;
    }
};