from typing import List


class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        diff = [0] * 52
        for l, r in ranges:
            if l > right or r < left:
                continue
            diff[left if l < left else l] += 1
            diff[(right if r > right else r) + 1] -= 1

        curr = diff[left - 1]
        for i in range(left, right + 1):
            curr += diff[i]
            if curr <= 0:
                return False
        return True


solution = Solution()
print(solution.isCovered([[1, 2], [3, 4], [5, 6]], 2, 5))
print(solution.isCovered([[1, 10], [10, 20]], 21, 21))
print(
    solution.isCovered([[15, 36], [15, 23], [15, 44], [30, 49], [2, 19], [27, 36], [7, 42], [12, 41]], 19, 47))  # True
