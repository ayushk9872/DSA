class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int duplicate = -1;
        int missing = 1;

        for (int i = 1; i < nums.size(); i++) {

        
            if (nums[i] == nums[i - 1]) {
                duplicate = nums[i];
            }


            else if (nums[i] > nums[i - 1] + 1) {
                missing = nums[i - 1] + 1;
            }
        }

        
        if (nums[nums.size() - 1] != nums.size()) {
            missing = nums.size();
        }

        return {duplicate, missing};
    }
};