class Solution {
public:
    bool checkValidString(string s) {
        stack<int>st,cnt;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if( s[i]==')'){
                if(st.size()&&s[st.top()]=='(')
                    st.pop();
                else if(cnt.size()){
                    cnt.pop();
                }else{
                    return false;
                }
            }else{
                cnt.push(i);
            }
        }
        while(st.size()  && cnt.size() &&st.top()<cnt.top()){
            st.pop();
            cnt.pop();
        }
        return !st.size();
    }
};