# from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        if not nums:
            return False
        l, r = 0, len(nums) - 1
        if r == 0:
            return nums[0] == target

        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                return True
            if nums[l] == nums[mid] == nums[r]:
                l += 1
                r -= 1
            elif nums[l] <= nums[mid]:
                if nums[l] <= target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                if nums[mid] < target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1

        return False


# solution = Solution()
# print(solution.search([2, 5, 6, 0, 0, 1, 2], 0))
# print(solution.search([2, 5, 6, 0, 0, 1, 2], 3))
# print(solution.search([1, 1, 1, 1, 1, 1, 1, 1, 1, 13, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], 13))
