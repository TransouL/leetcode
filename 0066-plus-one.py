from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        for i in range(n - 1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                break
            else:
                digits[i] = 0
                if i == 0:
                    digits.insert(0, 1)
        return digits


solution = Solution()
print(solution.plusOne([1, 2, 3]))
print(solution.plusOne([4, 3, 2, 1]))
print(solution.plusOne([0]))
print(solution.plusOne([9, 9, 9]))
