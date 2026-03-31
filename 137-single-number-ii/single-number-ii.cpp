class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
        int st=1;
        while(st<nums.size()-1){
            if(nums[st]!=nums[st-1] && nums[st]!=nums[st+1]){
                return nums[st];
            }
            st++;
        } 
        return -1;
    }
};