class Solution:
    def validMountainArray(self, arr: list[int]) -> bool:
        inc = False
        dec = False
        i = 0
        while i in range(len(arr)-1) and arr[i] < arr[i+1]:
            inc = True
            i += 1
        while i in range(len(arr)-1) and arr[i] > arr[i+1]:
            dec = True
            i+=1
        i += 1
        if i != len(arr) or not inc or not dec:
            return False
        return True

def main():
    arr = [2, 1]
    sol = Solution()
    res = sol.validMountainArray(arr)
    print(res)

if __name__ == "__main__":
    main()
