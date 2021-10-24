from typing import List
from bisect import bisect_left


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        column = bisect_left(matrix[0], target)
        if column < n and matrix[0][column] == target:
            return True
        row = bisect_left([row[0] for row in matrix], target)
        if row < m and matrix[row][0] == target:
            return True

        x, y = 0, column - 1
        while x < row and y >= 0:
            if matrix[x][y] == target:
                return True
            if matrix[x][y] > target:
                y -= 1
            else:
                x += 1
        return False


solution = Solution()
print(solution.searchMatrix(
    matrix=[[1, 4, 7, 11, 15], [2, 5, 8, 12, 19], [3, 6, 9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30]],
    target=5))
print(solution.searchMatrix(
    matrix=[[1, 4, 7, 11, 15], [2, 5, 8, 12, 19], [3, 6, 9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30]],
    target=20))
print(solution.searchMatrix([[-5]], -5))
