class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int maxProfit = 0;
        for(int r = 1; r < prices.size(); ++r){
            if(prices[l] > prices[r]){
                l = r;
            }
            maxProfit = max(maxProfit, prices[r] - prices[l]);
        }
        return maxProfit;
    }
};
