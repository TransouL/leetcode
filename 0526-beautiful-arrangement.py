DIVIDE = [[False] * 16 for _ in range(16)]
DIVIDE[1] = [True] * 16
for i in range(2, 16):
    DIVIDE[i][1] = DIVIDE[i][i] = True
    for j in range(2, i):
        if i % j == 0:
            DIVIDE[i][j] = DIVIDE[j][i] = True

ANS = [0, 1, 2, 3] + [-1] * 12


class Solution:
    def countArrangement(self, n: int) -> int:
        if ANS[n] != -1:
            return ANS[n]

        ans = self.countArrangement(n - 1)

        def dfs(steps: int) -> None:
            nonlocal ans
            if steps == n:
                ans += 1
                return
            for j in range(1, n + 1):
                if DIVIDE[steps][j] and not pos_flag[j]:
                    pos_flag[j] = True
                    dfs(steps + 1)
                    pos_flag[j] = False

        pos_flag = [False] * (n + 1)
        for i in range(1, n):
            if DIVIDE[n][i]:
                pos_flag[i] = True
                dfs(2)
                pos_flag[i] = False

        ANS[n] = ans
        return ans


solution = Solution()
for i in range(1, 16):
    print(i, " -> ", solution.countArrangement(i))
