class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt=people.size(),i=0,j=people.size()-1;
        sort(people.begin(),people.end());
        while(i<=j){
            while(j>i && people[i]+people[j]>limit){
                j--;
            }
            if(i<j && people[i]+people[j]<=limit)
                cnt--;
            i++;j--;
        }
        return cnt;
    }
};