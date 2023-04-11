class Solution {
public:
    string removeStars(string s) {
        string st="";
        for(auto &it:s){
            if(it=='*'){
                if(st.size())
                    st.pop_back();
            }
            else
                st+=it;
        }
        return st;
    }
};