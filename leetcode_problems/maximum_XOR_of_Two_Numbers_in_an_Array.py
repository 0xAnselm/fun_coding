class Solution:
    def findMaximumXOR(self, nums: list[int]) -> int:
        """
        let ni and nj be the numbers such that xor between them produces maximum
        value among other pairs. let m be the max value.

        m = ni ^ nj
        => m ^ nj = (ni ^ nj) ^ nj
        =>        = ni ^ (nj ^ nj) # xor is associative
        =>        = ni ^ 0
        =>        = ni

        so, m ^ nj = ni

        We note that m is 31-bit integer so we guess bits of m and and with each nj,
        we check if the combination of m and nj will produce ni.

        So time complexity becomes O(32N) = O(N)
        :param nums:
        :return:
        """
        m, mask = 0, 0

        for i in range(32)[::-1]:
            mask ^= 1 << i
            prefixes = {n & mask for n in nums}

            tmp = m | (1 << i)

            if any(prefix ^ tmp in prefixes for prefix in prefixes):
                m = tmp

        return m

    def findMaximumXOR2(self, nums: list[int]) -> int:
        maxN = 0
        maxLen = len(bin(max(nums))[2:])
        for i in range(len(nums)-1):
            a = bin(nums[i])[2:]
            for j in range(i+1, len(nums)):
                b = bin(nums[j])[2:]
                a = a.zfill(maxLen)
                b = b.zfill(maxLen)
                t = ""
                for s in range(len(b)):
                    t += str(int(a[s]) ^ int(b[s]))
                    #
                if int(t, 2) > maxN:
                    maxN = int(t, 2)
        return maxN


def main():
    sol = Solution()
    nums = [*range(29)]
    print(sol.findMaximumXOR(nums))


if __name__ == "__main__":
    main()
