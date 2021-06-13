# The isBadVersion API is already defined for you.
# @param version, an integer
# @return an integer
# def isBadVersion(version):
def isBadVersion(version: int) -> bool:
    return version >= 4


class Solution:
    def firstBadVersion(self, n: int) -> int:
        l, r = 1, n
        while l < r:
            middle = (l + r) // 2
            if isBadVersion(middle):
                r = middle
            else:
                l = middle + 1
        return r


solution = Solution()
print(solution.firstBadVersion(4))
print(solution.firstBadVersion(5))
print(solution.firstBadVersion(6))
print(solution.firstBadVersion(7))
print(solution.firstBadVersion(8))
print(solution.firstBadVersion(9))
print(solution.firstBadVersion(10000))
