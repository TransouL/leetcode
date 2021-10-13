from typing import List


class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        def getIdx(num):
            return num // size if num >= 0 else ((num + 1) // size) - 1

        buckets = {}
        size = t + 1
        for i, num in enumerate(nums):
            index = getIdx(num)
            if index in buckets:
                return True
            l, r = index - 1, index + 1
            if l in buckets and abs(num - buckets[l]) <= t:
                return True
            if r in buckets and abs(num - buckets[r]) <= t:
                return True

            buckets[index] = num
            if i >= k:
                buckets.pop(getIdx(nums[i - k]))

        return False


solution = Solution()
print(solution.containsNearbyAlmostDuplicate([1, 2, 3, 1], 3, 0))
print(solution.containsNearbyAlmostDuplicate([1, 0, 1, 1], 1, 2))
print(solution.containsNearbyAlmostDuplicate([1, 5, 9, 1, 5, 9], 2, 3))
