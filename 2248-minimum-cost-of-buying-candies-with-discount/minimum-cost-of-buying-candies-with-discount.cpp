class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if(cost.size() ==1){

            return cost[0];

        }if(cost.size()==2){
            return cost[0]+cost[1];
        }
        int ans = 0 ;
        sort(cost.begin(), cost.end());
        int i=cost.size()-1;
        int count=0;
        while(i>=0){
            if(count==2){
                i--;
                count=0;
            }
            count++;
            if(i>=0){
                ans+=cost[i];
            };
            i--;
            
            
        }

        return ans;
    }
};