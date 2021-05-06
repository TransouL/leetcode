class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        def sumXor(x: int) -> int:
            if x & 3 == 0: return x
            if x & 3 == 1: return 1
            if x & 3 == 2: return x + 1
            if x & 3 == 3: return 0

        s, e = start >> 1, n & start & 1
        return (sumXor(s - 1) ^ sumXor(s + n - 1)) << 1 | e


solution = Solution()
print(solution.xorOperation(5, 0))
print(solution.xorOperation(4, 3))
print(solution.xorOperation(1, 7))
print(solution.xorOperation(10, 5))
