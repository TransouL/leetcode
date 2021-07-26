from typing import List


class Solution:
    def minOperations(self, target: List[int], arr: List[int]) -> int:
        n = len(target)
        mp = {element: index for index, element in enumerate(target)}

        d = []
        for val in arr:
            if val in mp:
                idx = mp[val]
                if not d or idx > d[-1]:
                    d.append(idx)
                elif idx <= d[0]:
                    d[0] = idx
                else:
                    l, r = 0, len(d) - 1
                    while l < r:
                        mid = (l + r) // 2
                        if d[mid] < idx:
                            l = mid + 1
                        else:
                            r = mid
                    d[l] = idx

        return n - len(d)


solution = Solution()
print(solution.minOperations([5, 1, 3], [9, 4, 2, 3, 4]))  # 2
print(solution.minOperations([6, 4, 8, 1, 3, 2], [4, 7, 6, 2, 3, 8, 6, 1]))  # 3
