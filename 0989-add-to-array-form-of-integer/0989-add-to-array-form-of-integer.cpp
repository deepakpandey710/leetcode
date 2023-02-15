class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>ans;
        int n=num.size()-1;
        int c=0;
        while(n>=0){
            int x=num[n]+(k%10)+c;
            k/=10;
            ans.push_back(x%10);
            c=x/10;
            n--;
        }
        while(k>0){
            int x=k%10+c;
            ans.push_back(x%10);
            c=x/10;
            k/=10;
        }
        if(c!=0){
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};