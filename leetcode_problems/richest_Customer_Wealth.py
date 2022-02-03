class Solution:
    def individualWealth(self, acc: list) -> int:
        return sum(acc)

    def maximumWealth(self, accounts: list[list[int]]) -> int:
        maxW = 0
        for i in accounts:
            maxW = max(maxW, self.individualWealth(i))
        return maxW
def main():
    accounts = [[1,2,3],[3,2,1]]
    sol = Solution()
    print(sol.maximumWealth(accounts))

if __name__ == "__main__":
    main()
