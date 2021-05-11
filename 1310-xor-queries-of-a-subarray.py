from typing import List


class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        pre_xor, ans = [0], []
        for i in range(len(arr)):
            pre_xor.append(pre_xor[-1] ^ arr[i])
        for query in queries:
            ans.append(pre_xor[query[0]] ^ pre_xor[query[1] + 1])
        return ans


solution = Solution()
print(solution.xorQueries([1, 3, 4, 8], [[0, 1], [1, 2], [0, 3], [3, 3]]))
print(solution.xorQueries([4, 8, 2, 10], [[2, 3], [1, 3], [0, 0], [0, 3]]))
