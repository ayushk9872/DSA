class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> merged;
        double sum=0,median;
        for( int val_1:nums1){
            merged.push_back(val_1);
        }
        for(int val_2:nums2){
            merged.push_back(val_2);
        }
        std::sort(merged.begin(), merged.end());
        if((merged.size())%2==0){
            median=(merged[merged.size()/2]+merged[(merged.size()/2)-1])/2.0;
        }
        else{
            median=merged[((merged.size()+1)/2)-1];
        }
        
        return median;
    }
};