from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1
        return l if nums[l] == target else -1


solution = Solution()
print(solution.search([-1, 0, 3, 5, 9, 12], 9))
print(solution.search([-1, 0, 3, 5, 9, 12], 2))
