# from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        top, down, left, right = 0, n - 1, 0, n - 1
        matrix = [[0] * n for _ in range(n)]
        current = 1
        while current <= n * n:
            for i in range(left, right + 1):
                matrix[top][i] = current
                current += 1
            top += 1

            for i in range(top, down + 1):
                matrix[i][right] = current
                current += 1
            right -= 1

            for i in range(right, left - 1, -1):
                matrix[down][i] = current
                current += 1
            down -= 1

            for i in range(down, top - 1, -1):
                matrix[i][left] = current
                current += 1
            left += 1
        return matrix


# solution = Solution()
# print(solution.generateMatrix(3))
# print(solution.generateMatrix(1))
# print(solution.generateMatrix(4))

