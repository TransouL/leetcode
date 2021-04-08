# from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        if not nums:
            return -1
        l, r = 0, len(nums) - 1
        if r == 0:
            return nums[0]
        while l < r:
            mid = l + (r - l) // 2
            if nums[mid] < nums[r]:
                r = mid
            elif nums[mid] > nums[r]:
                l = mid + 1
            else:
                r -= 1
        return nums[l]


# solution = Solution()
# print(solution.findMin([3, 4, 5, 1, 2]))
# print(solution.findMin([4, 5, 6, 7, 0, 1, 2]))
# print(solution.findMin([1]))
# print(solution.findMin([2, 1]))
# print(solution.findMin([1, 2]))
# print(solution.findMin([2, 2, 2, 0, 1]))
# print(solution.findMin([2, 2, 2, 2, 2, 2, 2, 2, 2, 2]))
# print(solution.findMin([2, 2, 2, 2, 2, 1, 2, 2, 2, 2]))
