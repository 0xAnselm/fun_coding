class Solution:
    def wordPattern(self, p: str, s: str) -> bool:
        words, w_to_p = s.split(' '), dict()
        print(type(words))
        print(type(w_to_p))

        if (len(p) != len(words)) or (len(set(p)) != len(set(words))): 
            return False

        for i in range(len(words)):
            if words[i] not in w_to_p: 
                w_to_p[words[i]] = p[i]
            elif w_to_p[words[i]] != p[i]: 
                return False

        return True


def main():
    sol = Solution()
    pattern = "egg"
    s = "add"
    print(sol.wordPattern(pattern, s))


if __name__ == "__main__":
    main()
