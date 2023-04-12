class Solution {
public:
    string simplifyPath(string path) {
        string ans="";
        int i=0,n=path.size();
        vector<string>st;
        while(i<n){
            string cur="";
            while(i<n && path[i]!='/'){
                cur+=path[i];
                i++;
            }
            if(cur==".."){
                if(st.size())
                    st.pop_back();
            }
            else if(cur.size()&&cur!="."){
                st.push_back(cur);
            }
            i++;
        }
        for(auto it:st){
            ans+='/'+it;
        }
        return ans.size()?ans:"/";
    }
};