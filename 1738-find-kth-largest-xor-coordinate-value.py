from typing import List


class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        m, n = len(matrix), len(matrix[0])
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                f[i][j] = f[i - 1][j - 1] ^ f[i - 1][j] ^ f[i][j - 1] ^ matrix[i - 1][j - 1]
        return sorted([i for j in f[1:] for i in j], reverse=True)[k - 1]


solution = Solution()
print(solution.kthLargestValue([[5, 2], [1, 6]], 1))
print(solution.kthLargestValue([[5, 2], [1, 6]], 2))
print(solution.kthLargestValue([[5, 2], [1, 6]], 3))
print(solution.kthLargestValue([[5, 2], [1, 6]], 4))
