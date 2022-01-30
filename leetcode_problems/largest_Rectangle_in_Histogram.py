class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        self.heights = heights + [0]
        self.height = 0
        for i in range(len(self.heights)):
            res = self.expandBlock(i, i)
            if self.height < res[2]:
                self.height = res[2]
        return self.height

    def expandBlock(self, start, stop):
        rVal = start, stop, self.heights[start]*(stop-start)
        # print("start:", rVal[0], "stop:", rVal[1], "height:",
        #       rVal[2])
        if self.heights[start] <= self.heights[stop] and stop < len(self.heights)-1:
            return self.expandBlock(start, stop+1)
        return rVal
    
def main():
    sol = Solution()
    heights = [2, 1, 5, 6, 2, 3]
    heights = [2,1,2]
    print(sol.largestRectangleArea(heights))


if __name__ == "__main__":
    main()
