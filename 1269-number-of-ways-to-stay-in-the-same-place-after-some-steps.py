from functools import lru_cache


class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        @lru_cache(None)
        def dfs(curr: int, remains: int) -> int:
            if curr == remains: return 1
            count = dfs(curr, remains - 1)
            if curr > 0:
                count += dfs(curr - 1, remains - 1)
            if curr < arrLen - 1 and (remains - 1) > curr:
                count += dfs(curr + 1, remains - 1)
            return count % (10 ** 9 + 7)
        return dfs(0, steps)


solution = Solution()
print(solution.numWays(2, 4))
print(solution.numWays(3, 2))
print(solution.numWays(4, 2))
print(solution.numWays(3, 3))
print(solution.numWays(27, 7))
