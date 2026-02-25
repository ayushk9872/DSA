class Solution {
public:
    int countBits(int x) {
        return __builtin_popcount(x);  
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            
            int bitsA = countBits(a);
            int bitsB = countBits(b);
            if (bitsA == bitsB)
                return a < b;  
            
            return bitsA < bitsB;
        });
        
        return arr;
    }
};