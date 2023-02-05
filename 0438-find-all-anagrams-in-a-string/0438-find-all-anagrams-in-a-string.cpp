class Solution {
public:
    bool checkequal(int arr1[],int arr2[]){
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i])
                return 0;
        }
        return 1;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n=s.size();
        int m=p.size();
        if(n<m)return ans;
        int arr1[26]={0};
        for(int i=0;i<m;i++){
            arr1[p[i]-'a']++;
        }
        int i=0;
        int arr2[26]={0};
        while(i<m){
            arr2[s[i]-'a']++;
            i++;
        }
        if(checkequal(arr1,arr2))
            ans.push_back(0);
        while(i<n){
            arr2[s[i-m]-'a']--;
            arr2[s[i]-'a']++;
            i++;
            if(checkequal(arr1,arr2))
                ans.push_back(i-m);
        }
     return ans;   
    }
};