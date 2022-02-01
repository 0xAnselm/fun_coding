class Solution:
    def maxProfit(self, prices):
        l = 0
        r = 1
        maxV = 0
        while r < len(prices):
            tempV = prices[r] - prices[l]
            if prices[l] < prices[r]:
                maxV = max(tempV, maxV)
            else:
                l = r  # no solution in [l,r]
            r += 1
        return maxV

    def maxProfit2(self, prices: list[int]) -> int:
        if len(prices) < 2:
            return 0
        indMax = prices.index(max(prices))
        indMin = prices.index(min(prices))
        if indMax == 0:
            prices.pop(indMax)
            return self.maxProfit(prices)
        elif indMin == len(prices)-1:
            prices.pop(indMin)
            return self.maxProfit(prices)
        elif indMax < indMin:
            return max(self.maxProfit(prices[0:indMax+1]), self.maxProfit(prices[indMax:indMin+1]))
        elif indMin < indMax:
            return prices[indMax] - prices[indMin]


def main():
    # prices = [7, 1, 5, 3, 6, 4]
    prices = [2, 4, 1]
    # prices = [7,6,4,3,1]
    # prices = [2,1,2,0,1]
    sol = Solution()
    print(sol.maxProfit(prices))


if __name__ == "__main__":
    main()
