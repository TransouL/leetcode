# from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        if not matrix:
            return
        m, n, flag_col0 = len(matrix), len(matrix[0]), False

        for i in range(m):
            if matrix[i][0] == 0:
                flag_col0 = True
            for j in range(1, n):
                if not matrix[i][j]:
                    matrix[i][0] = matrix[0][j] = 0

        for i in range(m - 1, -1, -1):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
            if flag_col0:
                matrix[i][0] = 0


# solution = Solution()
# matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
# solution.setZeroes(matrix)
# print(matrix)
# matrix = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
# solution.setZeroes(matrix)
# print(matrix)
# matrix = []
# solution.setZeroes(matrix)
# print(matrix)
# matrix = None
# solution.setZeroes(matrix)
# print(matrix)
