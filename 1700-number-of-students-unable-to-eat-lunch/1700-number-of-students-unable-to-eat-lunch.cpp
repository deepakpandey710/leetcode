class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sw) {
        int i=0,j=0,n=st.size();
        queue<int>q;
        while(i<n && j<n){
            if(st[i]==sw[j]){
                st[i]=-1;
                j++;
            }else{
                q.push(st[i]);
            }
            i++;
        }
        
        while(q.size() && j<n){
            int m=q.size(),cnt=0;
            while(q.size() && j<n){
                int f=q.front();
                q.pop();
                if(f!=sw[j]){
                     q.push(f);
                }
                else
                    break;
                cnt++;
                if(m==cnt){
                    return q.size();
                }
            }
            if(q.size()){
                j++;
            }
            
        }
        return q.size();
        
    }
};