# from collections import Counter
# from typing import List


class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        count = Counter(answers)
        ans = sum((x + y) // (y + 1) * (y + 1) for y, x in count.items())
        return ans


# solution = Solution()
# print(solution.numRabbits([1,1,2]))
# print(solution.numRabbits([10,10,10]))
# print(solution.numRabbits([]))
