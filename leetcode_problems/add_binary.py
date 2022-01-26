class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a = a.rjust(len(b), "0")
        b = b.rjust(len(a), "0")
        result = ""
        cout = 0
        for i in range(max(len(a), len(b))-1,-1,-1):
            ai = int(a[i])
            bi = int(b[i])
            s = cout ^ (ai ^ bi)
            cout = (ai & bi) | (ai & cout) | (bi & cout)
            result = str(s) + result
        if cout:
            result = str(cout) + result
        return result


def main():
    a = "1"
    b = "111"
    sol = Solution()
    print(sol.addBinary(a, b))


if __name__ == "__main__":
    main()
