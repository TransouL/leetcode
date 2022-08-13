from typing import List


class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        arrcopy = arr.copy()
        arrcopy.sort()
        n = len(arr)

        ans, currCntOrig, currCntOrder, max_ = 0, 0, 0, -1

        for i in range(n):
            orig, order = arr[i], arrcopy[i]
            if orig == max_:
                currCntOrig += 1
            elif orig > max_:
                max_ = orig
                currCntOrig = 0

            if i != 0 and order == arrcopy[i - 1]:
                currCntOrder += 1
            else:
                currCntOrder = 0

            if max_ == order and currCntOrig == currCntOrder:
                ans += 1

        return ans


solution = Solution()
print(solution.maxChunksToSorted([5, 4, 3, 2, 1]))
print(solution.maxChunksToSorted([2, 1, 3, 4, 4]))
print(solution.maxChunksToSorted([1, 1, 0, 0, 1]))  # 2
