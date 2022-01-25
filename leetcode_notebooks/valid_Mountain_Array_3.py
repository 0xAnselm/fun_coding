class Solution:
    def validMountainArray(self, arr: list[int]) -> bool:
        i = 0
        j = len(arr)-1
        if j+1 < 3:
            return False
        while i < j:
            if arr[i] < arr[i+1]:
                i += 1
            else:
                break
        while i < j:
            if arr[j-1] > arr[j]:
                j -= 1
            else:
                break
        if i == j and i != 0 and j != len(arr)-1:
            return True
        else: 
            return False

def main():
    arr = [0,1,2,3,4,5,6,7,8,9]
    sol = Solution()
    res = sol.validMountainArray(arr)
    print(res)

if __name__ == "__main__":
    main()
