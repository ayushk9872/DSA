class Solution {
public:
    bool helper(int n, int i){
        int sum=0;
        while(n>0){
            sum += n%10;
            n/=10;
        }
        return sum==i;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0 ;i<nums.size();i++){
            if(helper(nums[i],i)) return i;
        }

        return -1;
    }
};