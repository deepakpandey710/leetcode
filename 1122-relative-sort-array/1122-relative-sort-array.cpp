class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mpp;
        for(auto &it:arr1){
            mpp[it]++;
        }
        vector<int>ans;
        for(int i=0;i<arr2.size();i++){
            if(mpp.find(arr2[i])!=mpp.end()){
                for(int j=0;j<mpp[arr2[i]];j++){
                    ans.push_back(arr2[i]);
                }
                mpp.erase(arr2[i]);
            }
        }
        for(auto &it:mpp){
            for(int j=0;j<it.second;j++){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};