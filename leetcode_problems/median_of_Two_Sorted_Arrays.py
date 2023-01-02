class Solution:
    def findMedianSortedArrays(self, nums1, nums2) -> float:
        result = nums1 + nums2
        result = sorted(result)
        result_len = len(result)
        if (result_len % 2):
            return result[int(result_len / 2)]
        else:
            result = result[int(result_len / 2)-1:int(result_len / 2)+1]
            return(sum(result)/2)
    
    def merge(self, nums1, nums2):
        p1 = 0
        p2 = 0
        n = max(len(nums1), len(nums2))
        result = []
        if (not len(nums1)):
            return nums2
        if (not len(nums2)):
            return nums1
        return result

def main():
    sol=Solution()
    nums1=[1, 3, 4, 6, 8, 9]
    nums2=[2, 7]
    a = sol.findMedianSortedArrays(nums1, nums2)
    print(a)

if __name__ == "__main__":
    main()
