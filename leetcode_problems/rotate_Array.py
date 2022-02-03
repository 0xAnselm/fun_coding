class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        rPtr = len(nums)
        nums[:] = nums[-k % rPtr:rPtr] + nums[:-k % rPtr]


def main():
    sol = Solution()
    nums = [1, 2, 3, 4, 5, 6, 7]
    k = 3
    nums = [-1, -100, 3, 99]
    k = 2
    nums = [1, 2]
    k = 5
    sol.rotate(nums, k)


if __name__ == "__main__":
    main()
