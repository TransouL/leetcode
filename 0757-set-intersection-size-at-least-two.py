from typing import List


class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        ans, n, m = 0, len(intervals), 2
        vars = [[] for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(intervals[i][0], intervals[i][0] + m - (len(vars[i]))):
                ans += 1
                for p in range(i - 1, -1, -1):
                    if intervals[p][1] < j:
                        break
                    vars[p].append(j)
        return ans


solution = Solution()
print(solution.intersectionSizeTwo([[1, 3], [1, 4], [2, 5], [3, 5]]))
print(solution.intersectionSizeTwo([[1, 2], [2, 3], [2, 4], [4, 5]]))
