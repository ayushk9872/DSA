class Solution {
public:
    
    bool checkDivisibility(int n) {
        int sum=0,c=n;
        int p=1;
        while(n>0){
            sum += n%10;
            p *= n%10 ;
            n/=10;
        }
        return c%(sum+p)==0;
        
    }
};