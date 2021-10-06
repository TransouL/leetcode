from typing import List


class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        found, n, first, second, third = 1, len(nums), nums[0], -1, -1
        for i in range(1, n):
            num = nums[i]
            if found == 1:
                if num > first:
                    second, first, found = first, num, 2
                elif num < first:
                    second, found = num, 2
            elif found == 2:
                if num > first:
                    third, second, first, found = second, first, num, 3
                elif first > num > second:
                    third, second, found = second, num, 3
                elif second > num:
                    third, found = num, 3
            else:
                if num > first:
                    third, second, first = second, first, num
                elif first > num > second:
                    third, second = second, num
                elif second > num > third:
                    third = num
        return third if found == 3 else first


solution = Solution()
print(solution.thirdMax([3, 2, 1]))
print(solution.thirdMax([1, 2]))
print(solution.thirdMax([2, 2, 3, 1]))
