#
# @lc app=leetcode.cn id=121 lang=python3
#
# [121] 买卖股票的最佳时机
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return self.helper(prices)

    def helper(self, prices):
        import math
        min_price = math.inf
        best_profit = 0
        for cur_price in prices:
            # 每天都想下,如果今天我以历史最低价格卖的话能赚多少?
            best_profit = max(best_profit, cur_price - min_price)
            # 每天都尝试保存下历史最低价格,方便未来比较.
            min_price = min(min_price, cur_price)
        return best_profit

    def method_brute_force(self, prices):
        profit = 0
        n = len(prices)
        if n < 2:
            return profit
        for i_buy in range(n):
            for i_sell in range(i_buy + 1,n):
                cur_profit = prices[i_sell] - prices[i_buy]
                profit = max(profit, cur_profit)
        return profit


# @lc code=end

