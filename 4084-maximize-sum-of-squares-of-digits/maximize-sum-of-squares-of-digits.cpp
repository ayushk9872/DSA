class Solution {
private:
    int sqofdigit(int n){
        int sq = 0;
        while(n > 0){
            int d = n % 10;
            sq += d * d;
            n /= 10;
        }
        return sq;
    }

public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return ""; 
        if (sum == 0 && num > 1) return ""; 

        string ans = "";

        for (int i = 0; i < num; i++) {
            int digit = min(9, sum);
            ans += (char)('0' + digit);
            sum -= digit;
        }

        if (sum != 0) return "";

        return ans;
    }
};
