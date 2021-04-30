from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        for i in range(32):
            total = 0
            for num in nums:
                total += (num >> i) & 1
            if total % 3:
                if i == 31:
                    result -= (1 << i)
                else:
                    result |= (1 << i)
        return result


solution = Solution()
print(solution.singleNumber([2, 2, 3, 2]))
print(solution.singleNumber([0, 1, 0, 1, 0, 1, 99]))
print(solution.singleNumber([1, 2147483647, 1, 1]))
print(solution.singleNumber([2147483647, 2147483647, 1, 2147483647]))
