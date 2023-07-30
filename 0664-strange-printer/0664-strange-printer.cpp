class Solution {
public:
    // int strangePrinter(string s) {
    //     vector<int>d(26,0);
    //     for(auto &it:s){
    //         d[it-'a']++;
    //     }
    //     int mx=0, ch=0;
    //     for(int i=0;i<26;i++){
    //         if(d[i]>mx){
    //             ch=i;
    //             mx=d[i];
    //         }
    //     }
    //     int cnt=1,p=-1;
    //     for(auto &it:s){
    //         if(it-'a'!=ch){
    //             if(it-'a'!=p){
    //                 p=it-'a';
    //                 cnt++;
    //             }
    //         }
    //     }
    //     return cnt;
    // }
    
    int n;
    vector<vector<int>> dp;
    int f(int i, int j, string& s){       
        if (dp[i][j]!=-1) return dp[i][j];
        if (i==j) return dp[i][j]=1;
        int ans;
        if (s[i]==s[j]||s[j-1]==s[j]) ans=f(i, j-1, s);
        else if (s[i]==s[i+1]) ans=f(i+1, j, s);
        else{
            ans=f(i,j-1, s)+1;
            for(int k=i+1; k<j; k++){
                if(s[k]==s[j])
                    ans=min(ans, f(i, k-1, s)+f(k, j-1, s));
            }
        }
        return dp[i][j]=ans;
    }
    int strangePrinter(string s) {
        n=s.size();
        dp.assign(n, vector<int>(n, -1));
        return f(0, n-1, s);
    }
};