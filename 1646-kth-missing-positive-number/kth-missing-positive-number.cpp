class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> nums(arr.back() + 1, 0);

        for (int x : arr) {
            nums[x] = -1;
        }

        int count = 0;
        for (int i = 1; i < nums.size(); i++) {  
            if (nums[i] != -1) {
                count++;
                if (count == k) {
                    return i;
                }
            }
        }
        return arr.back() + (k - count);
    }
};
