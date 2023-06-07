class Solution {
public:
    string bits(int n){
        string s="";
        while(n){
            int x=n%2;
            s+=(x+'0');
            n/=2;
        }
        return s;
    }
    int minFlips(int a, int b, int c) {
        string t1=bits(a);
        string t2=bits(b);
        string t3=bits(c);
        cout<<t1<<" t2: "<<t2<<"t3  "<<t3<<endl;
        int n=max({t1.size(),t2.size(),t3.size()});
        while(t1.size()<n){
            t1+='0';
        }
        while(t2.size()<n){
            t2+='0';
        }
        while(t3.size()<n){
            t3+='0';
        }
        int ans=0;
        for(int i=0;i<n;i++){
            cout<<t1[i]<<" "<<t2[i]<<" "<<t3[i]<<endl;
            int d=((t1[i]-'0')+(t2[i]-'0'));
            if((t3[i]-'0')){
                if(!d)
                    ans++;
            }else{
                ans+=d;
            }
        }
        return ans;
    }
};