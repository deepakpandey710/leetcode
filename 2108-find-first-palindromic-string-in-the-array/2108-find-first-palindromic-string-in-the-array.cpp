class Solution {
public:
    bool isPalin(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto &s:words){
            if(isPalin(s))return s;
        }
        return "";
    }
};