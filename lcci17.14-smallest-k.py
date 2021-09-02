from typing import List
import heapq


class Solution:
    def smallestK(self, arr: List[int], k: int) -> List[int]:
        if k == 0:
            return []
        hp = [-x for x in arr[:k]]
        heapq.heapify(hp)
        for i in range(k, len(arr)):
            if -hp[0] > arr[i]:
                heapq.heappushpop(hp, -arr[i])

        return [-x for x in hp]


solution = Solution()
print(solution.smallestK([1, 3, 5, 7, 2, 4, 6, 8], 4))
