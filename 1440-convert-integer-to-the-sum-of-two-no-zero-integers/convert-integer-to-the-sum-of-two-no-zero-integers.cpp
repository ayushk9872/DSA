class Solution {
private:
    bool isnotzero(int num){
            if(num<=0){
                return false;

            }
            while(num>0){
                if(num%10==0){
                    return false;
                }
                num/=10;

            }
            return true;
        }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            int b=n-i;
            if(isnotzero(i) && isnotzero(b)){
                return{i,b};
            }
        }
        return {};
    }
};