from typing import List


class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        n = len(candiesCount)
        pre_sum = [0] * (n + 1)
        for i in range(n):
            pre_sum[i + 1] = pre_sum[i] + candiesCount[i]

        ans = []
        for favoriteType, favoriteDay, dailyCap in queries:
            eat_range_l = favoriteDay + 1
            eat_range_r = eat_range_l * dailyCap
            target_type_l = 1 if favoriteType == 0 else pre_sum[favoriteType] + 1
            target_type_r = pre_sum[favoriteType + 1]
            ans.append(eat_range_l <= target_type_r and target_type_l <= eat_range_r)
        return ans


solution = Solution()
print(solution.canEat([7, 4, 5, 3, 8], [[0, 2, 2], [4, 2, 4], [2, 13, 1000000000]]))
print(solution.canEat([5, 2, 6, 4, 1], [[3, 1, 2], [4, 10, 3], [3, 10, 100], [4, 100, 30], [1, 3, 1]]))
