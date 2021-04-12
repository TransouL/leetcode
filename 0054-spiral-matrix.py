# from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix or not matrix[0]:
            return list()
        top, down, left, right = 0, len(matrix) - 1, 0, len(matrix[0]) - 1
        result = list()
        while True:
            for i in range(left, right + 1):
                result.append(matrix[top][i])
            top += 1
            if top > down:
                break

            for i in range(top, down + 1):
                result.append(matrix[i][right])
            right -= 1
            if right < left:
                break

            for i in range(right, left - 1, -1):
                result.append(matrix[down][i])
            down -= 1
            if down < top:
                break

            for i in range(down, top - 1, -1):
                result.append(matrix[i][left])
            left += 1
            if left > right:
                break
        return result


# solution = Solution()
# print(solution.spiralOrder([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))
# print(solution.spiralOrder([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]))
# print(solution.spiralOrder([]))
# print(solution.spiralOrder([[]]))
# print(solution.spiralOrder(None))

