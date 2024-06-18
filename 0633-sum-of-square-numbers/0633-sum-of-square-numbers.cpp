class Solution {
public:
    bool isPerfectSquare(long double x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0) {
 
        long long sr = sqrt(x);
         
        // if product of square root 
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}
    bool judgeSquareSum(int c) {
        long i=0;
        while(c-(i*i)>=0){
            long d=c-(i*i);
            // cout<<i<<d<<endl;
            if(isPerfectSquare(d)){
                return true;
            }
            i++;
        }
        return false;
    }
};