class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestby=prices[0],profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>bestby){
                profit=max(profit,prices[i]-bestby);
            }
            bestby=min(prices[i],bestby);

        }
        return profit;

    }
};