from typing import List
from collections import Counter


class UnionFindSet(object):
    def __init__(self, n):
        self.root = [i for i in range(n)]
        self.rank = [1] * n
        self.cnt = n

    def find(self, x):
        if x == self.root[x]:
            return x
        self.root[x] = self.find(self.root[x])
        return self.root[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x != root_y:
            if self.rank[root_x] > self.rank[root_y]:
                self.root[root_y] = root_x
            elif self.rank[root_x] < self.rank[root_y]:
                self.root[root_x] = root_y
            else:
                self.root[root_y] = root_x
                self.rank[root_x] += 1
            self.cnt -= 1

    def isConnected(self, x, y):
        return self.find(x) == self.find(y)


class Solution:
    def largestComponentSize(self, nums: List[int]) -> int:
        uf = UnionFindSet(max(nums) + 1)
        for num in nums:
            i = 2
            while i * i <= num:
                if num % i == 0:
                    uf.union(num, i)
                    uf.union(num, num // i)
                i += 1
        return max(Counter(uf.find(num) for num in nums).values())


solution = Solution()
print(solution.largestComponentSize([4, 6, 15, 35]))
print(solution.largestComponentSize([20, 50, 9, 63]))
print(solution.largestComponentSize([2, 3, 6, 7, 4, 12, 21, 39]))
