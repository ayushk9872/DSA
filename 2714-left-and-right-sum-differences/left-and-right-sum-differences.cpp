class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total=0, current=0;
        for(int x : nums){
            total += x;
        }
        vector<int> ans(nums.size(),0);
        vector<int> leftsum(nums.size(),0);
        vector<int> rightsum(nums.size(),0);
        for(int i=0 ; i<nums.size() ; i++){
        
            if(i==0){
                leftsum[i]=0;
                rightsum[i]=total-nums[i];
                current += nums[i];
            }else if(i == nums.size()-1){
                rightsum[i]=0;
                leftsum[i]=current;
            }else{
                leftsum[i]=current;
                rightsum[i]=total-current-nums[i];
                current += nums[i];
            }
        }
        for(int i=0 ; i< nums.size() ; i++){
            ans[i]=abs(leftsum[i]-rightsum[i]);
        }
        return ans;
        
    }
};