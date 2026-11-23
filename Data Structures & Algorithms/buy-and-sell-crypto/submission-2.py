class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProfit = 0;
        minPrice = prices[0]
        for i in range(len(prices)):
            minPrice = min(minPrice, prices[i])
            profit = prices[i] - minPrice
            maxProfit = max(maxProfit, profit)
        return maxProfit
        