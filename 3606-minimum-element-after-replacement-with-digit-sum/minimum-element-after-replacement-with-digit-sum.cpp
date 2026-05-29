class Solution {
public:
    int helper(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        for(int i=0 ; i<nums.size() ;i++){
            nums[i]=helper(nums[i]);
        }
        int m=INT_MAX;
        for(int x: nums){
            m=min(x,m);
        }
        return m;
        
    }
};