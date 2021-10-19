from typing import List
from collections import Counter


class Solution:
    def minMoves(self, nums: List[int]) -> int:
        # return sum(nums) - min(nums) * len(nums)
        max_value = max(nums)
        num_cnt = Counter(nums)
        max_count = num_cnt.pop(max_value)
        print(sorted(num_cnt.items(), reverse=True))
        ans, last_num = 0, max_value
        for num, count in sorted(num_cnt.items(), reverse=True):
            diff, last_num = last_num - num, num
            ans += diff * max_count
            max_value += diff * (max_count - 1)
            max_count += count
        return ans


solution = Solution()
print(solution.minMoves([1, 2, 3]))
print(solution.minMoves([1, 1, 1]))
print(solution.minMoves([-100, 0, 100]))  # 300
print(solution.minMoves([83, 86, 77, 15, 93, 35, 86, 92, 49, 21]))  # 487
