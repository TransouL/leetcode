from typing import List


class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack, nextNum = [], {}
        for i in range(len(nums2) - 1, -1, -1):
            while stack and nums2[i] > stack[-1]:
                stack.pop()
            if not stack:
                nextNum[nums2[i]] = -1
            else:
                nextNum[nums2[i]] = stack[-1]
            stack.append(nums2[i])

        ans = [-1] * len(nums1)
        for i, num in enumerate(nums1):
            ans[i] = nextNum[num]
        return ans


solution = Solution()
print(solution.nextGreaterElement(nums1=[4, 1, 2], nums2=[1, 3, 4, 2]))
print(solution.nextGreaterElement(nums1=[2, 4], nums2=[1, 2, 3, 4]))
