class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int n=s.size(),i=0,mx=0;
        while(i<k){
            if(isVowel(s[i])){
                mx++;
            }
            i++;
        }
        int j=0,cnt=mx;
        while(i<n){
            if(isVowel(s[i])){
                cnt++;
            }
            if(isVowel(s[j])){
                cnt--;
            }
            i++;
            j++;
            mx=max(mx,cnt);
        }
        return mx;
    }
};