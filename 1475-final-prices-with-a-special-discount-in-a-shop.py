from typing import List


class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        ans = prices.copy()
        st = [prices[-1]]
        for i in range(n - 2, -1, -1):
            while st and st[-1] > prices[i]:
                st.pop()
            if st:
                ans[i] -= st[-1]
            st.append(prices[i])
        return ans


solution = Solution()
print(solution.finalPrices(prices=[8, 4, 6, 2, 3]))
print(solution.finalPrices(prices=[1, 2, 3, 4, 5]))
print(solution.finalPrices(prices=[10, 1, 1, 6]))
