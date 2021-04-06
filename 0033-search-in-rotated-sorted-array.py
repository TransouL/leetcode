# from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1
        l, r = 0, len(nums) - 1
        if r == 0:
            return 0 if nums[0] == target else -1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                return mid
            if nums[l] <= nums[mid]:
                if nums[l] <= target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                if nums[mid] < target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1

        return -1


# solution = Solution()
# print(solution.search([4, 5, 6, 7, 0, 1, 2], 0))
# print(solution.search([4, 5, 6, 7, 0, 1, 2], 3))
# print(solution.search([1], 0))

