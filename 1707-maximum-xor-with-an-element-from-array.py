import math
from typing import List


class BinaryTrie:
    def __init__(self, high_bit=0):
        # zero子树指向表示 0 的子节点
        self.zero = None
        # one子树指向表示 1 的子节点
        self.one = None
        # high_bit表示BinaryTrie中最高位的编号，从0开始
        self.high_bit = high_bit
        self.min_value = float("inf")

    def insert(self, val: int) -> None:
        node = self
        node.min_value = min(node.min_value, val)
        for i in range(self.high_bit, -1, -1):
            bit = (val >> i) & 1
            if bit == 0:
                if not node.zero:
                    node.zero = BinaryTrie()
                node = node.zero
            else:
                if not node.one:
                    node.one = BinaryTrie()
                node = node.one
            node.min_value = min(node.min_value, val)

    def getMaxXorWithLimit(self, val: int, limit: int) -> int:
        node = self
        if node.min_value > limit:
            return -1

        ans = val & (2**31 - 1 << (self.high_bit + 1))
        for i in range(self.high_bit, -1, -1):
            bit = (val >> i) & 1
            if bit == 0:
                if node.one and node.one.min_value <= limit:
                    node = node.one
                    ans |= 1 << i
                else:
                    node = node.zero
            else:
                if node.zero and node.zero.min_value <= limit:
                    node = node.zero
                    ans |= 1 << i
                else:
                    node = node.one
        return ans


class Solution:
    def maximizeXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        # 确定最大的数，来确定最高位的二进制位编号
        max_num = max(nums)
        high_bit = math.floor(math.log(max_num, 2))

        bt = BinaryTrie(high_bit)
        for num in nums:
            bt.insert(num)

        ans = []
        for x, m in queries:
            ans.append(bt.getMaxXorWithLimit(x, m))

        return ans


solution = Solution()
print(solution.maximizeXor([0, 1, 2, 3, 4], [[3, 1], [1, 3], [5, 6]]))
print(solution.maximizeXor([5, 2, 4, 6, 6, 3], [[12, 4], [8, 1], [6, 3]]))
print(solution.maximizeXor(
    [537623, 4096, 4096, 7351703, 4096, 2790666, 3810100, 3596649, 2771788, 1751995, 1414302, 22158312, 15941567,
     32835966, 4096, 26516532, 3772313, 687681, 4096, 2902600],
    [[17484496, 1000000000], [391935295, 158969], [389948163, 1000000000], [530828903, 207846853],
     [1000000000, 1000000000], [1000000000, 1000000000], [276739277, 1000000000], [350541283, 1000000000],
     [343329183, 1000000000], [382830042, 225644], [1000000000, 2302405], [3708384, 1000000000],
     [330902154, 1000000000], [1000000000, 4024838], [527385402, 142642], [312288482, 1000000000],
     [1000000000, 1000000000], [19929306, 3787993], [15768874, 1000000000], [27944430, 172704181]]
))
