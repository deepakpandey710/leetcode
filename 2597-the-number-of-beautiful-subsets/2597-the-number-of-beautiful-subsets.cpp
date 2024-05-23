class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 1;
        map<int, map<int, int>> freq;
        for (int& x: nums) {
            freq[x % k][x]++;
        }
        for (auto& fr: freq) {
            int n = fr.second.size(), curr, next1 = 1, next2;
            vector<pair<int, int>> s(fr.second.begin(), fr.second.end());
            for (int i = n - 1; i >= 0; i--) {
                int skip = next1;
                int take = (1 << s[i].second) - 1;
                if (i + 1 < n && s[i + 1].first - s[i].first == k) {
                    take *= next2;
                } else {
                    take *= next1;
                }
                curr = skip + take;
                next2 = next1; next1 = curr;
            }
            result *= curr;
        }
        return result - 1;
    }
};