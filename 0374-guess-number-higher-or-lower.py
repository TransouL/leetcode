# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:


# 以pick为6来测试
def guess(num: int) -> int:
    if num < 6: return 1
    elif num > 6: return -1
    else: return 0


class Solution:
    def guessNumber(self, n: int) -> int:
        l, r = 1, n
        while l < r:
            m = l + (r - l) // 2
            checkm = guess(m)
            if checkm == 0:
                return m
            elif checkm < 0:
                r = m - 1
            else:
                l = m + 1
        return r


solution = Solution()
print(solution.guessNumber(10))
print(solution.guessNumber(14))
print(solution.guessNumber(2**31-1))

