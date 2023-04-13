class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size(),i=0,j=0;
        stack<int>st;
        while(j<n){
            if(st.size() &&st.top()==popped[j]){
                st.pop();
                j++;
            }
            else{
                while(i<n && pushed[i]!=popped[j]){
                    st.push(pushed[i]);
                    i++;
                }
                if(i==n)return false;
                i++;
                j++;
            }
        }
        return true;
    }
};