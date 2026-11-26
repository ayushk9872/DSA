class Solution {
public:
    bool canAliceWin(int n) {
        int to_remove=10;
        int turn=0;
        while(n >= to_remove){
            n-=to_remove;
            to_remove-=1;
            turn++; 
        }
        if(turn%2!=0){
            return true;
        }
        return false;
        
    }
};