class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0 ; i<s.length() ; i++){
            int val=122-s[i]+1;
            sum += val*(i+1);
        }
        return sum;
        
    }
};