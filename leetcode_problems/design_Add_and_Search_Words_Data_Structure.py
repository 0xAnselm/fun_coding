import re
# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
class WordDictionary:

    def __init__(self):
        self.l = []
        self.dot = False

    def addWord(self, word: str) -> None:
        if word not in self.l:
            self.l.append(word)
        if len(word) == 1:
            self.dot = True

    def search(self, word: str) -> bool:
        if word == ".":
            return self.dot
        for token in self.l:
            # m = re.match(r'\b' + word + r'\b', token)
            if re.match(r'\b' + word + r'\b', token):
                # print(token, word, m)
                return True
        return False


def main():
    wordDictionary = WordDictionary()
    wordDictionary.addWord("at")
    wordDictionary.addWord("and")
    wordDictionary.addWord("an")
    wordDictionary.addWord("add")
    wordDictionary.search("a")
    wordDictionary.search(".at")
    wordDictionary.addWord("bat")
    wordDictionary.search(".at")
    wordDictionary.search("an.")
    wordDictionary.search("a.d.")
    wordDictionary.search("b.")
    wordDictionary.search("a.d")
    wordDictionary.search(".")
    # null

if __name__ == "__main__":
    main()
