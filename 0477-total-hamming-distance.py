from typing import List


class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        # n = len(nums)
        # ans = 0
        # for i in range(30):
        #     c = sum((num >> i) & 1 for num in nums)
        #     ans += c * (n - c)
        # return ans
        return sum((c := sum((num >> i) & 1 for num in nums)) * (len(nums) - c) for i in range(30))


solution = Solution()
print(solution.totalHammingDistance([4, 14, 2]))
print(solution.totalHammingDistance([4, 14, 4]))