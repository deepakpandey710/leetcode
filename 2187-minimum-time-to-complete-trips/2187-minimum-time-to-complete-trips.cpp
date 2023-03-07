class Solution {
public:
    long long trips(vector<int>&time,long long mid){
        long long mx=0;
        for(auto &it:time){
            mx+=(mid/it);
        }
        return mx;
        
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans=0;
        // sort(time.begin(),time.end());
        long long h=(long long)totalTrips*(long long)time[0];
        long long l=0;
        while(l<h){
            long long mid=l+(h-l)/2;
            if(trips(time,mid)>=totalTrips){
                h=mid;
            }
            else{
                l=mid+1;
            }
        }
        return h;
    }
};  