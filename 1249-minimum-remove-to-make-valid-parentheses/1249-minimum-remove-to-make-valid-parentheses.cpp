class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        // int l=0,e=n-1;
        // while(l<e){
        //     if(s[l]==')'){
        //         s.erase(l,1);
        //     }
        //     else if(s[e]=='(')
        //         s.erase(e,1);
        //     else if(s[l]=='('){
        //        if(s[e]==')')
        //             {l++;e--;}
        //         else
        //             e--;
        //     }
        //     else if(s[e]==')'){
        //         if(s[l]=='(')
        //             {l++;e--;}
        //         else
        //             l++;
        //     }
        //     else
        //         {l++;e--;}
        // }
        // if(l==e && (s[l]==')' || s[e]=='('))
        //     s.erase(l,1);
        
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }
                else{
                    s[i]='*';
                }
            }
        }
        while(!st.empty()){
            s[st.top()]='*';
            st.pop();
        }
        s.erase(remove(s.begin(),s.end(),'*'),s.end()) ;
        return s;
    }
};