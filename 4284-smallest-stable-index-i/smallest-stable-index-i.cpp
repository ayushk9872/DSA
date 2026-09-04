class Solution {
private:
    int maximum(vector<int> nums,int ending){
        int ma=INT_MIN;
        for(int i=0 ; i<= ending ; i++){
            ma=max(ma,nums[i]);
        }
        return ma;
    }
    int minimum(vector<int> nums,int starting){
        int ma=INT_MAX;
        for(int i=starting ; i<nums.size() ; i++){
            ma=min(ma,nums[i]);
        }
        return ma;
    }
public:

    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> stable(nums.size(),0);
        for(int i= 0 ; i< nums.size() ; i++){
            if(maximum(nums,i)-minimum(nums,i)<=k){
                stable[i]=1;
            }
        }
        for(int i=0 ; i<stable.size() ; i++){
            if(stable[i]==1){
                return i;
            }   
        }
        return -1;
        
    }
};