class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        bool inc1 = false, dec = false, inc2 = false;
        int i = 0;

        while (i + 1 < n && nums[i] < nums[i + 1]) {
            inc1 = true;
            i++;
        }

        while (i + 1 < n && nums[i] > nums[i + 1]) {
            if (!inc1) return false;
            dec = true;
            i++;
        }

        while (i + 1 < n && nums[i] < nums[i + 1]) {
            if (!dec) return false;
            inc2 = true;
            i++;
        }

        return inc1 && dec && inc2 && i == n - 1;
    }
};
