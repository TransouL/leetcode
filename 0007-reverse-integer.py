class Solution:
    INT_MIN, INT_MAX = -2 ** 31, 2 ** 31 - 1

    def reverse(self, x: int) -> int:
        ans = 0
        while x != 0:
            if ans < self.INT_MIN // 10 + 1 or ans > self.INT_MAX // 10:
                return 0
            digit = x % 10
            if x < 0 and digit > 0:
                digit -= 10

            ans = ans * 10 + digit
            x = (x - digit) // 10
        return ans


solution = Solution()
print(solution.reverse(123))
print(solution.reverse(-123))
print(solution.reverse(120))
print(solution.reverse(0))
