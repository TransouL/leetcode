from typing import List


class Solution:
    def permutation(self, s: str) -> List[str]:
        def dfs(s_: str, steps: int) -> None:
            if steps == n:
                ans.append(s_)
                return
            for i in range(n):
                if not visited[i] and (i == 0 or visited[i - 1] or (s_sorted[i] != s_sorted[i - 1])):
                    visited[i] = True
                    s_next = s_ + s_sorted[i]
                    dfs(s_next, steps + 1)
                    visited[i] = False

        s_list = list(s)
        s_list.sort()
        s_sorted = "".join(s_list)
        ans = []
        n = len(s_sorted)
        visited = [False] * n
        dfs("", 0)
        return list(ans)


solution = Solution()
print(solution.permutation("abc"))
print(solution.permutation("aba"))
