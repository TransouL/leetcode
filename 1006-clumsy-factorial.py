class Solution:
    def clumsy(self, N: int) -> int:
        return (1, 2, 6, 7)[N - 1] if N <= 4 else N + (1, 2, 2, -1)[N & 3]


#solution = Solution()
#print(solution.clumsy(4))
#print(solution.clumsy(10))
