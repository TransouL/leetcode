from typing import List


class Solution:
    def unhappyFriends(self, n: int, preferences: List[List[int]], pairs: List[List[int]]) -> int:
        pairing = [0] * n
        for x, y in pairs:
            pairing[x] = y
            pairing[y] = x
        ans = 0
        for x in range(n):
            for u in preferences[x]:
                if u == pairing[x]:
                    break
                ux = preferences[u].index(x)
                uv = preferences[u].index(pairing[u])
                if ux < uv:
                    ans += 1
                    break
        return ans


solution = Solution()
print(solution.unhappyFriends(4, [[1, 2, 3], [3, 2, 0], [3, 1, 0], [1, 2, 0]], [[0, 1], [2, 3]]))
print(solution.unhappyFriends(2, [[1], [0]], [[1, 0]]))
print(solution.unhappyFriends(4, [[1, 3, 2], [2, 3, 0], [1, 3, 0], [0, 2, 1]], [[1, 3], [0, 2]]))
