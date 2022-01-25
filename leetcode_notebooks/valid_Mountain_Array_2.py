class Solution:
    def validMountainArray(self, arr: list[int]) -> bool:
        top = arr.index(max(arr))
        print(arr[top::1])
        if top == 0 or top == len(arr)-1:
            return False
        for i in range(top):
            if not (arr[i] < arr[i+1]):
                return False
        for i in range(top, len(arr)-1):
            if not (arr[i] > arr[i+1]):
                return False
        return True

def main():
    arr = [0,3,2,1]
    sol = Solution()
    res = sol.validMountainArray(arr)
    print(res)

if __name__ == "__main__":
    main()
