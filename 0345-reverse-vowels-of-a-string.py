class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        n, s = len(s), list(s)
        l, r = 0, n - 1
        while l < r:
            while l < r and s[l] not in vowels:
                l += 1
            while l < r and s[r] not in vowels:
                r -= 1
            if l < r:
                s[l], s[r] = s[r], s[l]
                l += 1
                r -= 1
        return "".join(s)


solution = Solution()
print(solution.reverseVowels("hello"))
print(solution.reverseVowels("leetcode"))
print(solution.reverseVowels("aA"))
