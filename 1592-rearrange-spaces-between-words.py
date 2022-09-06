class Solution:
    def reorderSpaces(self, text: str) -> str:
        start = 0
        blanks = 0
        words = []
        for i, ch in enumerate(text):
            if ch == ' ':
                if start != i:
                    words.append(text[start:i])
                start = i + 1
                blanks += 1
        if start != len(text):
            words.append(text[start:])
        wordsSize = len(words)
        if wordsSize == 1:
            return words[0] + " " * blanks
        return (" " * (blanks // (wordsSize - 1))).join(words) + (" " * (blanks % (wordsSize - 1)))


solution = Solution()
print(solution.reorderSpaces("  this   is  a sentence "))
print(solution.reorderSpaces(" practice   makes   perfect"))
print(solution.reorderSpaces("hello   world"))
print(solution.reorderSpaces("  walks  udp package   into  bar a"))
print(solution.reorderSpaces("a"))
