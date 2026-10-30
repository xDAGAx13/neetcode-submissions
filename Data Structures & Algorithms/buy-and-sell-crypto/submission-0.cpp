class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int curMin = prices[0];
        for(int i = 0; i<prices.size();i++){
          curMin = min(prices[i], curMin);
          int profit = prices[i] - curMin;
          maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};
