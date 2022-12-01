class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        if s[0:int(len(s)/2)].count("a") + s[0:int(len(s)/2)].count("e") + s[0:int(len(s)/2)].count("i") + s[0:int(len(s)/2)].count("o") + s[0:int(len(s)/2)].count("u") + s[0:int(len(s)/2)].count("A") + s[0:int(len(s)/2)].count("E") + s[0:int(len(s)/2)].count("I") + s[0:int(len(s)/2)].count("O") + s[0:int(len(s)/2)].count("U") == s[int(len(s)/2):].count("a") + s[int(len(s)/2):].count("e") + s[int(len(s)/2):].count("i") + s[int(len(s)/2):].count("o") + s[int(len(s)/2):].count("u") + s[int(len(s)/2):].count("A") + s[int(len(s)/2):].count("E") + s[int(len(s)/2):].count("I") + s[int(len(s)/2):].count("O") + s[int(len(s)/2):].count("U"):
            return True
        return False


def main():
    sol = Solution()
    s = "Uo"
    
    a = sol.halvesAreAlike(s)
    print(a)

if __name__ == "__main__":
    main()
