class Solution:
    def findComplement(self, num: int) -> int:
        if num == 0:
            return 1
        ans, bit_value = 0, 1
        while num != 0:
            has_bit = num % 2 == 0
            if has_bit:
                ans += bit_value
            num >>= 1
            bit_value *= 2
        return ans


solution = Solution()
print(solution.findComplement(5))
print(solution.findComplement(1))
