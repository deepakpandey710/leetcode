class Solution {
public:
    //////// incorrect but don't know why/////////////
    vector<vector<int>>dp;
//     int subs(int i,string s,string t,int k){
//         if(i==s.size()){
//             return t.size()-1;
//         }
//         char prev=t[t.size()-1];
//         if(dp[i][prev]!=-1){
//             cout<<t<<endl;
//             return dp[i][prev];
//         }
//         int take=0;
//         int nottake=subs(i+1,s,t,k);
//         if(t.size()==1 || (t.size()>1 && abs(s[i]-t[t.size()-1])<=k)){
            
//             take=subs(i+1,s,t+s[i],k);
//         }
//         return dp[i][prev]=max(take,nottake);
//     }
//     int longestIdealString(string s, int k) {
//         int n=s.size();
//         dp.resize(n+1,vector<int>(150,-1));
//         string t="#";
//         return subs(0,s,t,k);
//     }
    
    int subs(int i,string &s,int prev,int &k){
        if(i==s.size())return 0;
        if(dp[i][prev]!=-1)return dp[i][prev];
        int take=0;
        int nottake=subs(i+1,s,prev,k);
        if(prev==0 || abs(s[i]-prev)<=k)
            take=1+subs(i+1,s,s[i],k);
        return dp[i][prev]=max(take,nottake);
    }
    int longestIdealString(string s, int k) {
        int n=s.size();
        dp.resize(n,vector<int>(150,-1));
        return subs(0,s,0,k);
    }

};