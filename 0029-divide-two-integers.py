MIN, MAX = -2 ** 31, 2 ** 31 - 1


class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == MIN:
            if divisor == 1:
                return MIN
            if divisor == -1:
                return MAX

        rev = False
        if dividend > 0:
            dividend = -dividend
            rev = not rev
        if divisor > 0:
            divisor = -divisor
            rev = not rev

        if dividend > divisor or dividend == 0:
            return 0
        if dividend == divisor:
            return -1 if rev else 1

        candidates = [divisor]
        while candidates[-1] >= dividend - candidates[-1]:
            candidates.append(candidates[-1] + candidates[-1])

        ans = 0
        for i in range(len(candidates) - 1, -1, -1):
            if candidates[i] >= dividend:
                ans += 1 << i
                dividend -= candidates[i]

        return -ans if rev else ans


solution = Solution()
print(solution.divide(10, 3))
print(solution.divide(7, -3))
print(solution.divide(-1, 1))
