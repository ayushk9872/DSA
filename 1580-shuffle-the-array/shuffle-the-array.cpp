class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int j=0;
        vector<int> ans(nums.size(),0);
        for(int i=0 ;i<nums.size()/2;i++){
            ans[j]=nums[i];
            j+=2;
        }
        j=1;
        for(int i=nums.size()/2 ;i<nums.size();i++){
            ans[j]=nums[i];
            j+=2;
        }
        return ans;

    }
};