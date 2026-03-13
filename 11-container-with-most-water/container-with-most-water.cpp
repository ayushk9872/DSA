class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int maxwater=0;
        while(left<right){
            int width=right-left;
            int current_height=min(height[left],height[right]);
            int current_water=width*current_height;
            maxwater=max(maxwater,current_water);
            if(height[left]<height[right]){
                left++;

            }else{
                right--;
            }
        }
        return maxwater;

        
    }
};