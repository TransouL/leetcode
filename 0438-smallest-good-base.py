import math


class Solution:
    def smallestGoodBase(self, n: str) -> str:
        nVal = int(n)
        mMax = math.floor(math.log2(nVal))
        for m in range(mMax, 1, -1):
            k = math.floor(math.pow(nVal, 1.0 / m))
            mul = sum = 1
            for i in range(m):
                mul *= k
                sum += mul
            if sum == nVal:
                return str(k)
        return str(nVal - 1)


solution = Solution()
print(solution.smallestGoodBase("13"))
print(solution.smallestGoodBase("4681"))
print(solution.smallestGoodBase("1000000000000000000"))
