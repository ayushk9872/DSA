class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum=0,max_sum=INT_MIN;
        for(int val:nums){
            current_sum+=val;
            max_sum=max(current_sum,max_sum);
            if(current_sum<0){
                current_sum=0;
            }
        }
        return max_sum;
    }
};