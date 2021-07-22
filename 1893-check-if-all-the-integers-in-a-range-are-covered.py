from typing import List


class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        range_buckets = [0] * 51
        for range_ in ranges:
            range_left = left if range_[0] <= left else range_[0]
            range_right = right if range_[1] >= right else range_[1]
            range_buckets[range_left] = max(range_buckets[range_left], range_right)
        covered, checked = range_buckets[left], left
        while covered < right:
            covered_bak = covered
            for i in range(checked + 1, covered + 2):
                covered = max(covered, range_buckets[i])
            if covered == covered_bak:
                return False

        return True


solution = Solution()
print(solution.isCovered([[1, 2], [3, 4], [5, 6]], 2, 5))
print(solution.isCovered([[1, 10], [10, 20]], 21, 21))
print(
    solution.isCovered([[15, 36], [15, 23], [15, 44], [30, 49], [2, 19], [27, 36], [7, 42], [12, 41]], 19, 47))  # True
