class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        min_price = float('inf')
        bestP = 0
        
        for p  in prices: 
           min_price = min(min_price, p)
           bestP = max(bestP, p-min_price)
        
        return bestP
