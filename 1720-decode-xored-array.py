from typing import List


class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        ans = [first]
        for i in encoded:
            ans.append(i ^ ans[-1])
        return ans


solution = Solution()
print(solution.decode([1, 2, 3], 1))
print(solution.decode([6, 2, 7, 3], 4))
