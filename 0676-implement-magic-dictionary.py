from typing import List
from collections import defaultdict


class MagicDictionary:

    def __init__(self):
        self.dict = defaultdict(list)

    def buildDict(self, dictionary: List[str]) -> None:
        for word in dictionary:
            n = len(word)
            self.dict[n].append(word)

    def search(self, searchWord: str) -> bool:
        def check(word1: str, word2: str) -> bool:
            n = len(word1)
            changed = False
            for i in range(n):
                if word[i] != searchWord[i]:
                    if changed:
                        return False
                    else:
                        changed = True
            return changed

        n = len(searchWord)
        for word in self.dict[n]:
            if check(word, searchWord):
                return True
        return False


magicDictionary = MagicDictionary()
magicDictionary.buildDict(["hello", "leetcode"])
print(magicDictionary.search("hello"))
print(magicDictionary.search("hhllo"))
print(magicDictionary.search("hell"))
print(magicDictionary.search("leetcoded"))
