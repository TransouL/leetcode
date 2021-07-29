class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.isEnd = False
        self.next = [None] * 26

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        node = self
        for c in word:
            index = ord(c) - ord('a')
            if not node.next[index]:
                node.next[index] = Trie()
            node = node.next[index]
        node.isEnd = True

    def searchPrefix(self, prefix: str) -> "Trie":
        node = self
        for c in prefix:
            index = ord(c) - ord('a')
            if not node.next[index]:
                return None
            node = node.next[index]
        return node

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        node = self.searchPrefix(word)
        return node is not None and node.isEnd

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        return self.searchPrefix(prefix) is not None


# Your Trie object will be instantiated and called as such:
trie = Trie()
trie.insert("apple");
print(trie.search("apple"))  # True
print(trie.search("app"))  # False
print(trie.startsWith("app"))  # True
trie.insert("app")
print(trie.search("app"))  # True
