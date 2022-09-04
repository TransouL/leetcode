from typing import List


class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        rows, cols = len(mat), len(mat[0])
        sumrows = [0] * rows
        sumcols = [0] * cols
        for i in range(rows):
            for j in range(cols):
                sumrows[i] += mat[i][j]
                sumcols[j] += mat[i][j]
        ans = 0
        for i in range(rows):
            if sumrows[i] == 1:
                for j in range(cols):
                    if mat[i][j] == 1:
                        if sumcols[j] == 1:
                            ans += 1
                        break
        return ans


solution = Solution()
print(solution.numSpecial([[1, 0, 0], [0, 0, 1], [1, 0, 0]]))
print(solution.numSpecial([[1, 0, 0], [0, 1, 0], [0, 0, 1]]))
print(solution.numSpecial([[0, 0, 0, 1],
                           [1, 0, 0, 0],
                           [0, 1, 1, 0],
                           [0, 0, 0, 0]]))
print(solution.numSpecial([[0, 0, 0, 0, 0],
                           [1, 0, 0, 0, 0],
                           [0, 1, 0, 0, 0],
                           [0, 0, 1, 0, 0],
                           [0, 0, 0, 1, 1]]))
