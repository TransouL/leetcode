from typing import List


class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        maxCost = max(costs)
        count = [0] * (maxCost + 1)
        ans = 0
        for cost in costs:
            count[cost] += 1
        for i in range(1, maxCost + 1):
            if coins >= i:
                canbuy = min(count[i], coins // i)
                ans += canbuy
                coins -= i * canbuy
            else:
                break
        return ans


solution = Solution()
print(solution.maxIceCream([1, 3, 2, 4, 1], 7))
print(solution.maxIceCream([10, 6, 8, 7, 7, 8], 5))
print(solution.maxIceCream([1, 6, 3, 1, 2, 5], 20))
