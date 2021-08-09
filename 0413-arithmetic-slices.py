from typing import List


class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        diffs = [nums[i + 1] - nums[i] for i in range(n - 1)]

        cons = []
        curr_count = 1
        for i in range(1, len(diffs)):
            if diffs[i] == diffs[i - 1]:
                curr_count += 1
            else:
                cons.append(curr_count)
                curr_count = 1
        cons.append(curr_count)

        ans = 0
        for count in cons:
            ans += count * (count - 1) // 2
        return ans


solution = Solution()
print(solution.numberOfArithmeticSlices([1, 2, 3, 4]))
print(solution.numberOfArithmeticSlices([1]))
