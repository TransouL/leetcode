class WordDictionary:

    def __init__(self):
        self.isEnd = False
        self.children = [None] * 26

    def addWord(self, word: str) -> None:
        node = self
        for ch in word:
            ch = ord(ch) - ord('a')
            if not node.children[ch]:
                node.children[ch] = WordDictionary()
            node = node.children[ch]
        node.isEnd = True

    def search(self, word: str) -> bool:
        def dfs(index: int, node: WordDictionary) -> bool:
            if index == len(word):
                return node.isEnd
            ch = word[index]
            if ch != '.':
                child = node.children[ord(ch) - ord('a')]
                if child is not None and dfs(index + 1, child):
                    return True
            else:
                for child in node.children:
                    if child is not None and dfs(index + 1, child):
                        return True
            return False

        return dfs(0, self)


wordDictionary = WordDictionary()
wordDictionary.addWord("bad")
wordDictionary.addWord("dad")
wordDictionary.addWord("mad")
print(wordDictionary.search("pad"))  # return False
print(wordDictionary.search("bad"))  # return True
print(wordDictionary.search(".ad"))  # return True
print(wordDictionary.search("b.."))  # return True
