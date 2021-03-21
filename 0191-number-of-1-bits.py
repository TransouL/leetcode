class Solution:
    def hammingWeight(self, n: int) -> int:
        result = 0
        while n:
            n &= n - 1
            result += 1
        return result


# solution = Solution()
# print(solution.hammingWeight(0b00000000000000000000000000001011))
# print(solution.hammingWeight(0b00000000000000000000000010000000))
# print(solution.hammingWeight(0b11111111111111111111111111111101))
