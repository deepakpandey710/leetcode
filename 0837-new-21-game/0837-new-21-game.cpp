class Solution {
public:
    int f(int i,int n,int k){
        if(k<=0){
            if(n>=0){
                return 1;
            }
            return 0;
        }
        if(i<=0)return 0;
        return f(i-1,n,k-i)+f(i-1,n,k);
    }
    double new21Game(int n, int k, int maxPts) {
        // int t=f(maxPts,n,k);
        // cout<<"t : "<<t<<endl;
        // return t/(k*maxPts*1.0);
        
                if(n==0 || k==0 ) return 1.0;
        vector<double> dp(k+maxPts+1,0);
        double sum = 0;
        //Dealing with base case when points greater than k
        for(int i=0;i<maxPts;i++){
            dp[k+i] = (k+i)<=n;
            //Calculating the initial window
            sum+=dp[k+i];
        }
        //Initial window value
        dp[k-1] = sum/maxPts;

        //Calculating other probabilities using the relation
        for(int i=k-2;i>=0;i--){
            dp[i] = dp[i+1] + ((dp[i+1] - dp[i+maxPts+1])/maxPts);
        }
        return dp[0];
    }
};