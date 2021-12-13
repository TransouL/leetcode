from math import sqrt, floor


class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        left, right = 0, floor(sqrt(c))
        while left <= right:
            sum = left * left + right * right
            if sum == c:
                return True
            if sum > c:
                right -= 1
            else:
                left += 1
        return False


solution = Solution()
print(solution.judgeSquareSum(5))
print(solution.judgeSquareSum(4))
print(solution.judgeSquareSum(3))
print(solution.judgeSquareSum(2))
print(solution.judgeSquareSum(1))
