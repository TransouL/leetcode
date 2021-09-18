from typing import List


def getPrimes(n: int) -> List[int]:
    flags = [True] * (n * 2)
    primes, curr = [2], 2
    while True:
        for i in range(2, n // curr + 2):
            flags[curr * i] = False
        j = curr + 1
        for j in range(curr + 1, n + 1):
            if flags[j]:
                primes.append(j)
                curr = j
                break
        if j == n:
            break
    return primes


class Solution:
    primes = getPrimes(1000)

    def minSteps(self, n: int) -> int:
        ans = 0
        curr_prime_idx = 0
        while n != 1:
            curr_prime = self.primes[curr_prime_idx]
            if n % curr_prime == 0:
                ans += curr_prime
                n //= curr_prime
            else:
                curr_prime_idx += 1
        return ans


solution = Solution()
print(solution.primes)
print(solution.minSteps(3))
print(solution.minSteps(1))
print(solution.minSteps(1000))
