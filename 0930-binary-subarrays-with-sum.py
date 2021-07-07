from typing import List


class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        presum = 0
        cnt = {}
        ans = 0
        for num in nums:
            if presum in cnt:
                cnt[presum] += 1
            else:
                cnt[presum] = 1
            presum += num
            if presum - goal in cnt:
                ans += cnt[presum - goal]
        return ans


solution = Solution()
print(solution.numSubarraysWithSum([1, 0, 1, 0, 1], 2))  # 4
print(solution.numSubarraysWithSum([0, 0, 0, 0, 0], 0))  # 15
print(solution.numSubarraysWithSum([0, 0, 0, 0, 1], 2))  # 0
print(solution.numSubarraysWithSum([0, 1, 1, 1, 1], 3))  # 3
print(solution.numSubarraysWithSum([0, 0, 0, 0, 0, 0, 1, 0, 0, 0], 0))  # 27
