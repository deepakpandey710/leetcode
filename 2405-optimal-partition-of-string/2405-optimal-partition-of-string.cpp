class Solution {
public:
    int partitionString(string s) {
        vector<int>dict(26,0);
        int cnt=1;
        for(auto &ch:s){
            if(dict[ch-'a']){
                for(int i=0;i<26;i++){
                    dict[i]=0;
                }        
                cnt++;
            }
            dict[ch-'a']++;
            
        }
        return cnt;
    }
};