class Solution {
public:
    int getLucky(string s, int k) {
        string res="";
        for(auto &ch:s){
            res+=to_string(ch-'a'+1);
        }
        int sm=0;
        while(k){
            sm=0;
            for(auto &ch:res){
                sm+=ch-'0';
            }
            k--;
            res=to_string(sm);
        }
        return sm;
    }
};