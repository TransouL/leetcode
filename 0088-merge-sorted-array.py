# from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        x, y = 0, 0
        while y < n:
            if x >= m + y or nums1[x] > nums2[y]:
                nums1.insert(x, nums2[y])
                y += 1
            x += 1
        del nums1[m + n:]


# solution = Solution()
# num1, num2 = [1, 2, 3, 0, 0, 0], [2, 5, 6]
# solution.merge(num1, 3, num2, 3)
# print(num1)
# num1, num2 = [1], []
# solution.merge([1], 1, num2, 0)
# print(num1)
