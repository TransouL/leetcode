from typing import List


class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n, max_len, ans = len(nums), 0, 0
        dp = [1] * n
        cnt = [1] * n
        for i, num_i in enumerate(nums):
            for j in range(i):
                if num_i > nums[j]:
                    if dp[i] < dp[j] + 1:
                        dp[i] = dp[j] + 1
                        cnt[i] = cnt[j]
                    elif dp[i] == dp[j] + 1:
                        cnt[i] += cnt[j]
            if max_len < dp[i]:
                max_len = dp[i]
                ans = cnt[i]
            elif max_len == dp[i]:
                ans += cnt[i]
        return ans


solution = Solution()
print(solution.findNumberOfLIS([1, 3, 5, 4, 7]))
print(solution.findNumberOfLIS([2, 2, 2, 2, 2]))
