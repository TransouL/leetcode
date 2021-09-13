from typing import List


class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        n = len(s)
        dp = [[0] * 26 for _ in range(n)] + [[n] * 26]

        for i in range(n - 1, -1, -1):
            si = ord(s[i])
            for j in range(26):
                dp[i][j] = dp[i + 1][j]
            dp[i][si - 97] = i  # 97: ord('a')

        ans, longest = "", 0
        for word in dictionary:
            wordLen = len(word)
            if wordLen < longest:
                continue
            match, sIdx = True, 0
            for wordIdx in range(len(word)):
                nextMatchedIdx = dp[sIdx][ord(word[wordIdx]) - 97]
                if nextMatchedIdx == n:
                    match = False
                    break
                sIdx = nextMatchedIdx + 1
            if match:
                if wordLen > longest:
                    longest = wordLen
                    ans = word
                elif wordLen == longest:
                    ans = min(ans, word)
        return ans


solution = Solution()
print(solution.findLongestWord("abpcplea", ["ale", "apple", "monkey", "plea"]))
print(solution.findLongestWord("abpcplea", ["a", "b", "c"]))
print(solution.findLongestWord("abpcplea",
                               ["ale", "apple", "monkey", "plea", "abpcplaaa", "abpcllllll", "abccclllpppeeaaaa"]))
print(solution.findLongestWord("aaa", ["aaa", "aa", "a"]))  # "aaa"
print(solution.findLongestWord("aab", ["aaa", "aa", "a"]))  # "aa"
