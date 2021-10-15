from typing import List


class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        n = len(num)
        ans = []

        def backtrack(expr: List[str], step: int, res: int, lastMul: int):
            if step == n:
                if res == target:
                    ans.append(''.join(expr))
                return
            nextSignIndex = len(expr)
            if step > 0:
                expr.append('')
            val = 0
            for j in range(step, n):
                if j > step and num[step] == '0':
                    break
                val = val * 10 + int(num[j])
                expr.append(num[j])
                if step == 0:
                    backtrack(expr, j + 1, val, val)
                else:
                    expr[nextSignIndex] = '+'
                    backtrack(expr, j + 1, res + val, val)
                    expr[nextSignIndex] = '-'
                    backtrack(expr, j + 1, res - val, -val)
                    expr[nextSignIndex] = '*'
                    backtrack(expr, j + 1, res - lastMul + lastMul * val, lastMul * val)
            del expr[nextSignIndex:]

        backtrack([], 0, 0, 0)
        return ans


solution = Solution()
print(solution.addOperators(num="123", target=6))
print(solution.addOperators(num="232", target=8))
print(solution.addOperators(num="105", target=5))
print(solution.addOperators(num="00", target=0))
print(solution.addOperators(num="3456237490", target=9191))
