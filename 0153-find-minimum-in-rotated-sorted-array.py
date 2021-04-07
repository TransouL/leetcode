# from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        if not nums:
            return -1
        l, r = 0, len(nums) - 1
        if r == 0:
            return nums[0]
        while l <= r:
            mid = (l + r) // 2
            if nums[l] <= nums[mid] <= nums[r]:
                return nums[l]
            elif nums[l] <= nums[mid]:
                l = mid + 1
            else:
                r = mid
        return -1


# solution = Solution()
# print(solution.findMin([3, 4, 5, 1, 2]))
# print(solution.findMin([4, 5, 6, 7, 0, 1, 2]))
# print(solution.findMin([1]))
# print(solution.findMin([2, 1]))
# print(solution.findMin([1, 2]))
# print(solution.findMin([3, 1, 2]))
