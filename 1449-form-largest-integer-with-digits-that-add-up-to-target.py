from typing import List


class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:
        dp = [0] * (target + 1)
        # 遍历digit时使用倒序，这样数字越来越小，挨个往后加即可；cost相同的数字取最大的，后面再出现直接忽略
        for i in (i_ for i_ in range(8, -1, -1) if cost[i_] <= target and dp[cost[i_]] == 0):
            dp[cost[i]] = i + 1
            for total in range(cost[i], target + 1):
                if dp[total - cost[i]] != 0:
                    dp[total] = max(dp[total], dp[total - cost[i]] * 10 + i + 1)
        return str(dp[target])


solution = Solution()
print(solution.largestNumber([4, 3, 2, 5, 6, 7, 2, 5, 5], 9))
print(solution.largestNumber([7, 6, 5, 5, 5, 6, 8, 7, 8], 12))
print(solution.largestNumber([2, 4, 6, 2, 4, 6, 4, 4, 4], 5))
print(solution.largestNumber([6, 10, 15, 40, 40, 40, 40, 40, 40], 47))
print(solution.largestNumber([9, 7, 15, 7, 6, 9, 9, 5, 10], 52))
