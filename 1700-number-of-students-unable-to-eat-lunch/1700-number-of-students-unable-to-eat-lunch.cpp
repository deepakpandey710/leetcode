class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sw) {
        int i=0,j=0,n=st.size();
        for(auto &it:st){
            if(it==1)i++;
            else j++;
        }
        for(auto &it:sw){
            if(it==0){
                if(j>0){
                    j--;n--;
                }else{
                    return n;
                }
            }else{
                if(i>0){
                    i--;n--;
                }else return n;
            }
        }
        return 0;
    }
};