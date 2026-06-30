class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;

        int maxProfit = 0;

        while(r < prices.size()){
            maxProfit = max(prices[r] - prices[l],maxProfit);

            if(prices[r] < prices[l]){
                l = r;
            }else{
                ++r;
            }
        }
        return maxProfit;
    }
};
