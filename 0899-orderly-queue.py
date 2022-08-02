class Solution:
    def orderlyQueue(self, s: str, k: int) -> str:
        if k == 1:
            ans = s
            for i in range(1, len(s)):
                ans = min(ans, s[i] + s[i + 1:] + s[:i])
            return ans
        return "".join((sorted(s)))


solution = Solution()
print(solution.orderlyQueue(s="cba", k=1))
print(solution.orderlyQueue(s="baaca", k=3))
