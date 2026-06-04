class Solution {
public:
    int helper(int n){
        if(n < 100){
            return 0;
        }
        int w=0;
        string s=to_string(n);
        for( int i=1 ;i < s.length()-1 ; i++){
            if(s[i] > s[i-1] && s[i] > s[i+1]){
                w++;
                
            }else if(s[i]<s[i-1] && s[i]<s[i+1]){
                w++;
            }
        }
        return w;
        
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1 ; i <= num2 ;i ++){
            ans += helper(i);
        }
        return ans;
        
    }
};