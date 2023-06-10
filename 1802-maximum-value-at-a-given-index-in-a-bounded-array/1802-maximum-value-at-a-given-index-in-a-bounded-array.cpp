class Solution {
public:
    // int sm(int i,int e){
    //     return e*i-(i*(i+1))/2;
    // }
    // int maxValue(int n, int i, int maxSum) {
    //     int h=maxSum,l=0,ans=0;
    //     while(l<=h){
    //         int mid=(l+h)/2;
    //         int ls=sm(min(i,mid-1),mid);
    //         ls+=max(0,i-mid+1);
    //         int rs=sm(min(n-i-1,mid-1),mid);
    //         rs+=max(0,n-i-mid);
    //         if(ls+rs+mid<=maxSum){
    //             ans=max(ans,mid);
    //             l=mid+1;
    //         }
    //         else{
    //             h=mid-1;
    //         }
    //     }
    //     return ans;
    // }
    
    
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int left = 0, right = maxSum, mid;
        while (left < right) {
            mid = (left + right + 1) / 2;
            if (test(n, index, mid) <= maxSum)
                left = mid;
            else
                right = mid - 1;
        }
        return left + 1;
    }

    long test(int n, int index, int a) {
        int b = max(a - index, 0);
        long res = long(a + b) * (a - b + 1) / 2;
        b = max(a - ((n - 1) - index), 0);
        res += long(a + b) * (a - b + 1) / 2;
        return res - a;
    }
};