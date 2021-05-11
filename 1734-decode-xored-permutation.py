from typing import List


class Solution:
    def decode(self, encoded: List[int]) -> List[int]:
        n = len(encoded) + 1
        total = 0
        for i in range(1, n + 1):
            total ^= i
        except_first = 0
        for i in encoded[1::2]:
            except_first ^= i
        ans = [total ^ except_first] + [0] * (n - 1)
        for i in range(1, n):
            ans[i] = encoded[i - 1] ^ ans[i - 1]
        return ans


solution = Solution()
print(solution.decode([3, 1]))
print(solution.decode([6, 5, 4, 6]))
