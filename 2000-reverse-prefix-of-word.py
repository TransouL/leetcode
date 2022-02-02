class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        n = len(word)
        first = word.find(ch, 0, n)
        print(first)
        if first != -1:
            return word[first::-1] + word[first + 1:]
        else:
            return word


solution = Solution()
print(solution.reversePrefix("abcdefd", 'd'))
print(solution.reversePrefix("xyxzxe", 'z'))
print(solution.reversePrefix("abcd", 'z'))
