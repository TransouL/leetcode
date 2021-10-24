from functools import lru_cache
from typing import List


class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        n = len(price)

        filter_special = []
        for sp in special:
            if sum(sp[i] * price[i] for i in range(n)) > sp[-1]:
                filter_special.append(sp)

        @lru_cache(None)
        def dfs(curr_need) -> int:
            min_price = sum(need * price[i] for i, need in enumerate(curr_need))
            for special in filter_special:
                special_price = special[-1]
                next_needs = []
                for i in range(n):
                    if special[i] > curr_need[i]:
                        break
                    next_needs.append(curr_need[i] - special[i])
                if len(next_needs) == n:
                    min_price = min(min_price, dfs(tuple(next_needs)) + special_price)
            return min_price

        return dfs(tuple(needs))


solution = Solution()
print(solution.shoppingOffers(price=[2, 5], special=[[3, 0, 5], [1, 2, 10]], needs=[3, 2]))
print(solution.shoppingOffers(price=[2, 3, 4], special=[[1, 1, 0, 4], [2, 2, 1, 9]], needs=[1, 2, 1]))
