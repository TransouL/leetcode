import math
from typing import List


# 哈希表解法
class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        # 确定最大的数，来确定最高位的二进制位编号
        max_num = max(nums)
        if max_num == 0: return 0
        high_bit = math.floor(math.log(max_num, 2))

        x = 0
        for k in range(high_bit, -1, -1):
            seen = set()
            for num in nums:
                seen.add(num >> k)
            x_next = x * 2 + 1
            found = False

            for num in nums:
                if x_next ^ (num >> k) in seen:
                    found = True
                    break
            if found:
                x = x_next
            else:
                x = x_next - 1

        return x


# 字典树解法
class Trie:
    def __init__(self, high_bit=0):
        # 最高位编号
        self.high_bit = high_bit
        self.left = None
        self.right = None

    def insert(self, num: int) -> None:
        curr = self
        for k in range(self.high_bit, -1, -1):
            bit = (num >> k) & 1
            if bit == 0:
                if not curr.left:
                    curr.left = Trie()
                curr = curr.left
            else:
                if not curr.right:
                    curr.right = Trie()
                curr = curr.right

    def search(self, num: int) -> int:
        curr = self
        result = 0
        for k in range(self.high_bit, -1, -1):
            bit = (num >> k) & 1
            if bit == 0:
                if curr.right:
                    curr = curr.right
                    result = result * 2 + 1
                else:
                    curr = curr.left
                    result = result * 2
            else:
                if curr.left:
                    curr = curr.left
                    result = result * 2 + 1
                else:
                    curr = curr.right
                    result = result * 2
        return result


class Solution2:
    def findMaximumXOR(self, nums: List[int]) -> int:
        # 确定最大的数，来确定最高位的二进制位编号
        max_num = max(nums)
        if max_num == 0: return 0
        high_bit = math.floor(math.log(max_num, 2))
        trie = Trie(high_bit)

        n = len(nums)
        ans = 0
        for i in range(1, n):
            trie.insert(nums[i - 1])
            ans = max(ans, trie.search(nums[i]))

        return ans


solution = Solution()
# solution = Solution2()
print(solution.findMaximumXOR([3, 10, 5, 25, 2, 8]))
print(solution.findMaximumXOR([0]))
print(solution.findMaximumXOR([2, 4]))
print(solution.findMaximumXOR([8, 10, 2]))
print(solution.findMaximumXOR([14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70]))
