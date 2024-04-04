class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int ans=0,n=0;
        for(auto &ch:s){
            if(ch=='('){
                st.push('(');
            }else if(ch==')'){
                st.pop();
            }
            n=st.size();
            ans=max(ans,n);
        }
        return ans;
    }
};