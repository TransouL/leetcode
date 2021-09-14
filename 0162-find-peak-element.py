from typing import List


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        def find(left: int, right: int) -> bool:
            nonlocal ans
            if right == left + 1:
                if nums[right] < nums[left] and (left == 0 or nums[left] > nums[left - 1]):
                    ans = left
                    return True
                return False

            mid = (left + right) // 2
            if nums[mid - 1] < nums[mid] > nums[mid + 1]:
                ans = mid
                return True

            rightPart = False
            if nums[mid] > nums[left]:
                rightPart = find(mid, right)
            if rightPart:
                return True
            return find(left, mid)

        ans = -1
        n = len(nums)
        if n == 1:
            return 0
        found = find(0, n - 1)
        return n - 1 if not found else ans


solution = Solution()
print(solution.findPeakElement([1, 2, 3, 1]))
print(solution.findPeakElement([1, 2, 1, 3, 5, 6, 4]))

