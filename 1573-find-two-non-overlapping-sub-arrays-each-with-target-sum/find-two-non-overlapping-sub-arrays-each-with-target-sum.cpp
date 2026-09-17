class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<int> best(n, INT_MAX);
        
        unordered_map<long long, int> mp;
        
        mp[0] = -1;
        
        long long prefixSum = 0;
        int ans = INT_MAX;
        int minLength = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];
            
            long long needed = prefixSum - target;
            
            if (mp.find(needed) != mp.end()) {
                int j = mp[needed] + 1;
                int currentLength = i - mp[needed];
                
                if (j - 1 >= 0 && best[j - 1] != INT_MAX) {
                    ans = min(ans, currentLength + best[j - 1]);
                }
                
                minLength = min(minLength, currentLength);
            }
            
            if (i == 0)
                best[i] = minLength;
            else
                best[i] = min(best[i - 1], minLength);
            
           
            mp[prefixSum] = i;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};