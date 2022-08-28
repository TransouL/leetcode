from typing import List


class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        ans = [0] * (n * 2)
        for i in range(n):
            ans[i * 2] = nums[i]
            ans[i * 2 + 1] = nums[i + n]
        return ans


solution = Solution()
print(solution.shuffle(nums=[2, 5, 1, 3, 4, 7], n=3))
print(solution.shuffle(nums=[1, 2, 3, 4, 4, 3, 2, 1], n=4))
print(solution.shuffle(nums=[1, 1, 2, 2], n=2))
