# from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        result = []
        n = len(nums)
        nums.sort()

        def helper(index: int, tmp: List[int]):
            result.append(tmp)
            for j in range(index, n):
                if j == index or nums[j] != nums[j - 1]:
                    helper(j + 1, tmp + [nums[j]])

        helper(0, [])
        return result


# solution = Solution()
# print(solution.subsetsWithDup([1, 2, 2]))
# print(solution.subsetsWithDup([0]))
# print(solution.subsetsWithDup([5, 5, 5, 5, 5]))
# print(solution.subsetsWithDup([4, 4, 4, 1, 4]))
# print(solution.subsetsWithDup([]))
