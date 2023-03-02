class Solution {
public:
    int compress(vector<char>& chars) {
        int ans=0,n=chars.size(),i=0,j=0;
        
        while(i<n){
            char ch=chars[i];
            int cnt=0;
            while(i<n&&ch==chars[i]){
                i++;
                cnt++;
            }
            chars[j++]=ch;
            ans++;
            string s=to_string(cnt);
            if(cnt>1){
                for(auto &it:s){
                    ans++;
                    chars[j++]=it;
                }
            }
        }
        return ans;
    }
};