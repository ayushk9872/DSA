class Solution {
public:
    int search(vector<int>& nums, int target) {
        int strt=0,end=nums.size()-1;
        while(strt<=end){
            int mid=end+strt/2;
            if (nums[mid]==target){
                return mid;

            }
            if(nums[strt]<=nums[mid]){
                if(nums[strt]<=target && target<=nums[mid]){
                    end=mid-1;
                }
                else{
                    strt=mid+1;

                }
            }
            else{
                if (nums[mid]<=target && target<=nums[end]){
                    strt=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};