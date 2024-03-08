class Solution {
public:
    vector<int> diStringMatch(string s) {
        int i=0,d=s.size();
        vector<int>ans;
        for( auto &it:s){
            if(it=='I'){
                ans.push_back(i++);
            }else if(it=='D'){
                ans.push_back(d--);
            }
        }
        ans.push_back(d--);
        return ans;
    }
};