class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for (auto &p : mp) {
            auto &v = p.second;
            if (v.size() >= 3) {
                for (int i = 0; i + 2 < v.size(); i++) {
                    int sum = abs(v[i] - v[i+1]) + abs(v[i+1] - v[i+2]) + abs(v[i+2] - v[i]);
                    ans = min(ans, sum);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};