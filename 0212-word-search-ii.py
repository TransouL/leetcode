from collections import defaultdict
from typing import List


class Trie:
    def __init__(self):
        self.children = defaultdict(Trie)
        self.word = ""

    def insert(self, word):
        curr = self
        for c in word:
            curr = curr.children[c]
        curr.word = word


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def dfs(currTire, x, y) -> None:
            ch = board[x][y]
            if ch not in currTire.children:
                return

            nxt = currTire.children[ch]
            if nxt.word != "":
                ans.append(nxt.word)
                nxt.word = ""

            if nxt.children:
                board[x][y] = '#'
                for xn, yn in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]:
                    if 0 <= xn < m and 0 <= yn < n:
                        dfs(nxt, xn, yn)
                board[x][y] = ch
            else:
                currTire.children.pop(ch)

        ans = []
        trie = Trie()
        for word in words:
            trie.insert(word)
        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                dfs(trie, i, j)
        return ans


solution = Solution()
print(solution.findWords([["o", "a", "a", "n"], ["e", "t", "a", "e"], ["i", "h", "k", "r"], ["i", "f", "l", "v"]],
                         ["oath", "pea", "eat", "rain"]))
print(solution.findWords([["a", "b"], ["c", "d"]], ["abcb"]))
