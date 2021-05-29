from typing import List
from collections import Counter


class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        def subarraySum(nums: List[int]) -> int:
            ret, preSum, counter = 0, 0, Counter([0])
            for num in nums:
                preSum += num
                if preSum - target in counter:
                    ret += counter[preSum - target]
                counter[preSum] += 1
            return ret

        raws, columns, ans = len(matrix), len(matrix[0]), 0
        for top in range(raws):
            total = [0] * columns
            for bottom in range(top, raws):
                for column in range(columns):
                    total[column] += matrix[bottom][column]
                ans += subarraySum(total)
        return ans



solution = Solution()
print(solution.numSubmatrixSumTarget([[0,1,0],[1,1,1],[0,1,0]], 0))
print(solution.numSubmatrixSumTarget([[1,-1],[-1,1]], 0))
print(solution.numSubmatrixSumTarget([[904]], 0))
