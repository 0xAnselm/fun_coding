class Solution:
    def uniqueOccurrences(self, arr) -> bool:
        occ = []
        seen = []
        for i in range(len(arr)):
                z = arr.count(arr[i])
                if (arr[i] in seen):
                    continue
                else:
                    seen.append(arr[i])
                if (z not in occ):
                    occ.append(z)
                else:
                    return False
        return True

def main():
    sol = Solution()
    arr = [1,2,2,1,1,3]
    print(sol.uniqueOccurrences(arr))


if __name__ == "__main__":
    main()