class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxR(prices.size(),0);
        int maxRight = INT_MIN;
        int maxProfit = 0;

        for(int i = prices.size()-1; i >= 0 ; i--){
            if(prices[i] > maxRight){
                maxRight = prices[i];
            }
            maxR[i] = maxRight;
            maxProfit = max(maxR[i]-prices[i],maxProfit);
        }

        return maxProfit;
    }
};
