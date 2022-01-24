class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word.islower():
            return True
        elif word.isupper():
            return True
        elif word[1:] == word[1:].lower():
            return True

def main():
    sol = Solution()
    print(sol.detectCapitalUse("USA"))
    print(sol.detectCapitalUse("leetcode"))
    print(sol.detectCapitalUse("Google"))

if __name__ == "__main__":
    main()