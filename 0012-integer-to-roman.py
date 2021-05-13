class Solution:
    THOUSANDS = ["", "M", "MM", "MMM"]
    HUNDREDS = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
    TENS = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
    ONES = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]

    def intToRoman(self, num: int) -> str:
        return Solution.THOUSANDS[num // 1000] + Solution.HUNDREDS[num % 1000 // 100] \
               + Solution.TENS[num % 100 // 10] + Solution.ONES[num % 10]


solution = Solution()
print(solution.intToRoman(3))
print(solution.intToRoman(4))
print(solution.intToRoman(9))
print(solution.intToRoman(58))
print(solution.intToRoman(1994))
print(solution.intToRoman(140))
print(solution.intToRoman(3999))
