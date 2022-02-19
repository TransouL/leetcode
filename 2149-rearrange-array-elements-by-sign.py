from typing import List


class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        sub1, sub2 = [], []
        for num in nums:
            if num > 0:
                sub1.append(num)
            else:
                sub2.append(num)
        ans = []
        for i in range(len(sub1)):
            ans.append(sub1[i])
            ans.append(sub2[i])
        return ans


solution = Solution()
print(solution.rearrangeArray([3, 1, -2, -5, 2, -4]))
print(solution.rearrangeArray([-1, 1]))
