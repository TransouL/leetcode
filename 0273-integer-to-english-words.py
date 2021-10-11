singles = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]
teens = ["Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
tens = ["", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
thousands = ["", "Thousand", "Million", "Billion"]


class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"

        def toEnglish(num: int) -> str:
            s = ""
            if num >= 100:
                s += singles[num // 100] + " Hundred "
                num %= 100
            if num >= 20:
                s += tens[num // 10] + " "
                num %= 10
            if num >= 10:
                s += teens[num - 10] + " "
            elif num > 0:
                s += singles[num] + " "
            return s

        s = ""
        unit = int(1e9)
        for i in range(3, -1, -1):
            curNum = num // unit
            if curNum:
                s += toEnglish(curNum) + thousands[i] + " "
                num -= curNum * unit
            unit //= 1000

        return s.rstrip()


solution = Solution()
print(solution.numberToWords(123))
print(solution.numberToWords(12345))
print(solution.numberToWords(1234567))
print(solution.numberToWords(1234567891))
print(solution.numberToWords(10))
print(solution.numberToWords(50868))
