class Solution:
    def fourSumCount(self, nums1: list[int], nums2: list[int], nums3: list[int], nums4: list[int]) -> int:
        res = 0
        abSumDict = {} # i.e. unordered Hashmap
        for i in nums1:
            for j in nums2:
                abSumDict[i+j] = abSumDict.get(i+j, 0)+1
        for k in nums3:
            for l in nums4:
                res += abSumDict.get(-k-l, 0)
        return res


def main():
    sol = Solution()
    nums1 = [1, 2]
    nums2 = [-2, -1]
    nums3 = [-1, 2]
    nums4 = [0, 2]
    print(sol.fourSumCount(nums1, nums2, nums3, nums4))


if __name__ == "__main__":
    main()
