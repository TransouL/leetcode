# from typing import List


class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        f, g = [1] * n, nums.copy()
        for i in range(1, n):
            for j in range(i):
                if f[j] >= f[i] and nums[i] % nums[j] == 0:
                    f[i] = f[j] + 1
                    g[i] = j
        max_len = max(f)
        index = f.index(max_len)

        answer = []
        while len(answer) < max_len:
            answer.append(nums[index])
            index = g[index]
        answer.reverse()
        return answer


# solution = Solution()
# print(solution.largestDivisibleSubset([1, 2, 3]))
# print(solution.largestDivisibleSubset([1, 2, 4, 8]))
# print(solution.largestDivisibleSubset([9, 18, 54, 90, 108, 180, 360, 540, 720]))
