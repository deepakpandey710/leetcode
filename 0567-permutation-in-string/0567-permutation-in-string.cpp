class Solution {
public:   
    bool equal(vector<int>&d1,vector<int>&d2){
        for(int i=0;i<26;i++){
            if(d1[i]!=d2[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int>d1(26,0),d2(26,0);
        for(auto &it:s1){
            d1[it-'a']++;
        }
        int n=s2.size(),m=s1.size();
        if(n<m)return false;
        for(int i=0;i<m;i++){
            d2[s2[i]-'a']++;
        }
        if(equal(d1,d2))return true;
        int j=0;
        for(int i=m;i<n;i++){
            d2[s2[j++]-'a']--;
            d2[s2[i]-'a']++;
            if(equal(d1,d2))return true;
        }
        
        return false;      
    }
};