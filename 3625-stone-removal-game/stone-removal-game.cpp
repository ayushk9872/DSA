class Solution {
public:
    bool canAliceWin(int n) {
        int to_remove=10;
        
        while(n >= to_remove){
            n-=to_remove;
            to_remove-=1;
             
        }
        if(to_remove%2==0){
            return false;
        }
        return true;
        
    }
};