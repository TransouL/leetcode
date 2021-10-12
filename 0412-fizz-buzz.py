from typing import List


class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        ans = list(map(str, list(range(1, n + 1))))
        for i in range(n):
            if (i + 1) % 15 == 0:
                ans[i] = "FizzBuzz"
            elif (i + 1) % 3 == 0:
                ans[i] = "Fizz"
            elif (i + 1) % 5 == 0:
                ans[i] = "Buzz"
        return ans


solution = Solution()
print(solution.fizzBuzz(15))
