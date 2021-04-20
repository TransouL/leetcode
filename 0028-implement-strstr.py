class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        if not haystack:
            return -1
        n, m = len(haystack), len(needle)
        if n < m:
            return -1
        for i in range(n - m + 1):
            is_matched = True
            for j in range(m):
                if haystack[i + j] != needle[j]:
                    is_matched = False
                    break
            if is_matched:
                return i
        return -1


# solution = Solution()
# print(solution.strStr("hello", "ll"))
# print(solution.strStr("aaaaa", "bba"))
# print(solution.strStr("", ""))
