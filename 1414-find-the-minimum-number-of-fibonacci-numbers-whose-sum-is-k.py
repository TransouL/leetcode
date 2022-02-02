class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        fib = [1, 1]
        while fib[-1] < k:
            fib.append(fib[-1] + fib[-2])
        ans, i = 0, len(fib) - 1
        while k:
            if k >= fib[i]:
                k -= fib[i]
                ans += 1
            i -= 1
        return ans


solution = Solution()
print(solution.findMinFibonacciNumbers(7))
print(solution.findMinFibonacciNumbers(10))
print(solution.findMinFibonacciNumbers(19))
