from typing import List


def binarySearchFirst(nums: List[int], size: int, target: int) -> int:
    left, right = 0, size - 1
    while left < right:
        mid = (left + right) // 2
        if nums[mid] < target:
            left = mid + 1
        elif nums[mid] == target:
            right = mid
        else:
            right = mid - 1
    if nums[left] == target:
        return left
    return -1


def binarySearchLast(nums: List[int], size: int, target: int) -> int:
    left, right = 0, size - 1
    while left < right:
        mid = (left + right + 1) // 2
        if nums[mid] < target:
            left = mid + 1
        elif nums[mid] == target:
            left = mid
        else:
            right = mid - 1
    return left


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        if n == 0:
            return [-1, -1]

        left = binarySearchFirst(nums, n, target)
        if left == -1:
            return [-1, -1]

        right = binarySearchLast(nums, n, target)
        return [left, right]


solution = Solution()
print(solution.searchRange([5, 7, 7, 8, 8, 10], 8))
print(solution.searchRange([5, 7, 7, 8, 8, 10], 6))
print(solution.searchRange([], 0))
print(solution.searchRange([2, 2], 3))
print(solution.searchRange([1], 1))
