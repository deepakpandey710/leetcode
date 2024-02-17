class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>maxh;
        for(int i=0;i<heights.size()-1;i++){
            int d=heights[i+1]-heights[i];
            if(d>0){
                maxh.push(-d);
            }
            if(maxh.size()>ladders){
                bricks+=maxh.top();
                maxh.pop();
            }
            if(bricks<0){
                return i;
            }
        }
        return heights.size()-1;
    }
};