class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_money = 0

        for buy in range(len(prices)):
            for sell in range (buy+1, len(prices)):
                profit = prices[sell] - prices[buy]
                if profit > max_money:
                    max_money = profit
        if max_money > 0:
            return max_money
        else:
            return 0

