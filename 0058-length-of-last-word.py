class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # return len(s.rstrip().split(" ")[-1])
        n, started_idx = len(s), -1
        for i in range(n - 1, -1, -1):
            if s[i] != ' ':
                if started_idx == -1:
                    started_idx = i
            else:
                if started_idx != -1:
                    return started_idx - i
        return 0 if started_idx == -1 else started_idx + 1



solution = Solution()
print(solution.lengthOfLastWord("Hello World"))
print(solution.lengthOfLastWord("   fly me   to   the moon  "))
print(solution.lengthOfLastWord("luffy is still joyboy"))
print(solution.lengthOfLastWord("a"))
print(solution.lengthOfLastWord("a "))
print(solution.lengthOfLastWord("   "))
