class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int j=0 ;
        int m=0;
        int prev_max=INT_MAX,prev_min=INT_MIN;
        int mx=INT_MIN, mn=INT_MAX;
        for(int i= 0 ; i< nums.size();i++){
            mx=max(mx,nums[i]);
            mn=min(mn,nums[i]);
            if(mx != prev_max){
                j=i;
                prev_max=mx;
            }
            if(mn != prev_min){
                m=i;
                prev_min=mn;
            }


        }
        int max_operations=max(j,m)+1;
        int oper=nums.size()-max(j,m)+min(j,m)+1;
        int op=nums.size()-min(j,m);
        return min(min(max_operations,oper),op);
    }
};