class Solution:
    def divideString(self, s: str, k: int, fill: str):
        div = len(s)//k
        rem = len(s) % k
        res = []
        if (rem):
            div += 1
        for i in range(div):
            sol = s[i*k:i*k+k]
            res.append(sol)
        if (rem):
            res[-1] = res[-1] ++ (k - rem) * fill
        return res


def main():
    sol = Solution()
    res = sol.divideString("abcdefghij", 3, "x")
    print(res)

if __name__ == "__main__":
    main()