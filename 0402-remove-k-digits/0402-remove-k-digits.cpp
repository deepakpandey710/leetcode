class Solution {
public:
//     string removeKdigits(string num, int k) {
//         int i=0,j=1,n=num.size();   
//         if(n==k)return "0";
//         while(j<n&&k>0){
//             if(num[j]>num[i]){
//                 num.erase(j,1);
//                 k--;
//             }else if(num[i]>num[j]){
//                 num.erase(i,1);
//                 k--;
//             }else{
//                 j++;
//             }
            
//         }
//         num.erase(i,k);
//         while(num[i]=='0'){
//             i++;
//         }
//         num.erase(0,i);
//         return num==""?"0":num;
//     }
    
     string removeKdigits(string num, int k) {
        int n=num.size();
        // if(n==k)
        //     return "0";
        int keep=n-k;
        string res;
        for(int i=0;i<n;i++){
            while(res.size()>0 && k>0 && num[i]<res.back()){
                k--;
                res.pop_back();
            }
            res.push_back(num[i]);
            
        }
        res.erase(keep,string::npos);
        int s=0;
        while(s<(int)res.size()-1 && res[s]=='0'){
            s++;    
        }
        res.erase(0,s);
        return res==""? "0":res ;
    }
};