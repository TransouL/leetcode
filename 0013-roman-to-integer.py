class Solution:
    SYMBOL_VALUES = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

    def romanToInt(self, s: str) -> int:
        ans = 0
        n = len(s)
        for i, c in enumerate(s):
            value = Solution.SYMBOL_VALUES[c]
            if i < n - 1 and value < Solution.SYMBOL_VALUES[s[i + 1]]:
                ans -= value
            else:
                ans += value
        return ans


solution = Solution()
print(3, solution.romanToInt("III"))
print(4, solution.romanToInt("IV"))
print(9, solution.romanToInt("IX"))
print(58, solution.romanToInt("LVIII"))
print(1994, solution.romanToInt("MCMXCIV"))
print(140, solution.romanToInt("CXL"))
print(3999, solution.romanToInt("MMMCMXCIX"))
