class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0;
        int n=fruits.size();
        if(n<=2)return n;
        map<int,int>mpp;
        int j=0;
        for(int i=0;i<n;i++){
            mpp[fruits[i]]++;
            if(mpp.size()>2){
                int sm=0;
                for(auto &it:mpp){
                    if(it.first!=fruits[i]){
                        sm+=it.second;
                    }
                    // cout<<it.first<<"  "<<it.second<<endl;
                }
                ans=max(ans,sm);
                while(j<i){
                    int x=fruits[j];
                    mpp[x]--;
                    j++;
                    if(mpp[x]<=0){
                        mpp.erase(x);
                        break;
                    }
                }
            }
        }
        int sm=0;
        for(auto &it:mpp){    
            sm+=it.second;                    
        }
        ans=max(ans,sm);
        return ans;
        
    }
};