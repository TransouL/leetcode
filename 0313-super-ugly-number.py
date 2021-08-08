from typing import List


class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        dp = [0] * n
        dp[0] = 1
        prime_count = len(primes)
        pointers = [0] * prime_count

        for i in range(1, n):
            next_cands = [dp[pointers[j]] * primes[j] for j in range(prime_count)]
            min_cand = min(next_cands)
            dp[i] = min_cand
            for j in range(prime_count):
                if next_cands[j] == min_cand:
                    pointers[j] += 1

        return dp[n - 1]


solution = Solution()
print(solution.nthSuperUglyNumber(12, [2, 7, 13, 19]))
print(solution.nthSuperUglyNumber(1, [2, 3, 5]))
