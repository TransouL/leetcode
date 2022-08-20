class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        sentence = ' ' + sentence
        idx = sentence.find(' ' + searchWord)
        return sentence[:idx].count(' ') + 1 if idx != -1 else -1


solution = Solution()
print(solution.isPrefixOfWord(sentence="i love eating burger", searchWord="burg"))
print(solution.isPrefixOfWord(sentence="this problem is an easy problem", searchWord="pro"))
