from typing import List
from collections import defaultdict


class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        sizeMp = defaultdict(list)
        for i, v in enumerate(groupSizes):
            sizeMp[v].append(i)
        ans = []
        for sz, ids in sizeMp.items():
            item = []
            for i, id in enumerate(ids):
                item.append(id)
                if i % sz == sz - 1:
                    ans.append(item)
                    item = []
        return ans



solution = Solution()
print(solution.groupThePeople([3, 3, 3, 3, 3, 1, 3]))
print(solution.groupThePeople([2, 1, 3, 3, 3, 2]))
