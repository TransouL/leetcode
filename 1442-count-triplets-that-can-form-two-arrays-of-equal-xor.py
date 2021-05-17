from collections import Counter
from typing import List


class Solution:
    def countTriplets1(self, arr: List[int]) -> int:
        pre_xor, ans = [0], 0
        n = len(arr)
        for val in arr:
            pre_xor.append(pre_xor[-1] ^ val)
        for i in range(n - 1):
            for k in range(i + 1, n):
                if pre_xor[i] == pre_xor[k + 1]:
                    ans += k - i
        return ans

    def countTriplets(self, arr: List[int]) -> int:
        cnt, total = Counter(), Counter()
        ans = x = 0
        for k, val in enumerate(arr):
            cnt[x] += 1
            total[x] += k
            x ^= val
            if x in cnt:
                ans += cnt[x] * k - total[x]
        return ans


solution = Solution()
print(solution.countTriplets([2, 3, 1, 6, 7]))
print(solution.countTriplets([1, 1, 1, 1, 1]))
print(solution.countTriplets([2, 3]))
print(solution.countTriplets([1, 3, 5, 7, 9]))
print(solution.countTriplets([7, 11, 12, 9, 5, 2, 7, 17, 22]))
