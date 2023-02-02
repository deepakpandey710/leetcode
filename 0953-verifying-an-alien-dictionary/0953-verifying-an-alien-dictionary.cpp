class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>dict(26);
        for(int i=0;i<26;i++){
            dict[order[i]-'a']=i;
        }
        for(int i=1;i<words.size();i++){
            int n=words[i].size(),m=words[i-1].size();
            int j=0;
            for(;j<min(n,m);j++){
                if(dict[words[i-1][j]-'a']>dict[words[i][j]-'a'])
                {
                    return false;
                }
                else if(dict[words[i-1][j]-'a']<dict[words[i][j]-'a']){
                    break;
                }
            }
            if(j==n && j!=m)return false;
        }
        
        return true;
    }
};