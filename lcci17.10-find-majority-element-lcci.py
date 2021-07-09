from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        can, count = 0, 0
        for num in nums:
            if count == 0:
                can, count = num, 1
            else:
                if num == can:
                    count += 1
                else:
                    count -= 1
        if count == 1 and can == nums[-1]:
            n, count2 = len(nums), 0
            for i in range(n - 1):
                if nums[i] == can:
                    count2 += 1
            return can if count2 * 2 == n - 1 else -1
        else:
            return can if count > 0 else -1


solution = Solution()
print(solution.majorityElement([1, 2, 5, 9, 5, 9, 5, 5, 5]))
print(solution.majorityElement([3, 2]))
print(solution.majorityElement([2, 2, 1, 1, 1, 2, 2]))
print(solution.majorityElement([1, 2, 3]))
