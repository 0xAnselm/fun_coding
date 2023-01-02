class Solution:
    def searchInsert(self, nums, target: int) -> int:
        l = 0
        r = len(nums) - 1
        if (target < nums[0]):
            return 0
        if (target > nums[r]):
            return len(nums)
        if (r == 1 and target == nums[0]):
            return 0
        return self.recursiveSearch(nums, target, l, r)

    def recursiveSearch(self, nums, target, l, r):
        m = int((l + r) / 2)
        if (l > r):
            return m+1

        if (target < nums[m]):
            return self.recursiveSearch(nums, target, l, m - 1)
        elif (target > nums[m]):
            return self.recursiveSearch(nums, target, m + 1, r)
        elif (target == nums[m]):
            return m
        return -1


def main():
    sol = Solution()
    nums = [1, 3, 5, 6]
    target = 2
    print(sol.searchInsert(nums, target))


if __name__ == "__main__":
    main()
