class Solution {
public:
    
    long long distinctNames(vector<string>& ideas) {
     long long ans=0;
        unordered_set<string>st[26];
        for(auto &it:ideas){
            st[it[0]-'a'].insert(it.substr(1));
        }
        for(int i=0;i<25;i++){
            for(int j=i+1;j<26;j++){
                int numb_mutual=0;
                for(auto &it:st[i]){
                    if(st[j].find(it)!=st[j].end()){
                        numb_mutual++;
                    }
                }
                ans+=2* ((st[i].size()-numb_mutual)*(st[j].size()-numb_mutual));
            }
        }
        return ans;
    }
};