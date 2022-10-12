from typing import List


class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        pos = [0] * 26
        for i, ch in enumerate(s):
            idx = ord(ch) - ord('a')
            pos[idx] = i - pos[idx]
        for j in range(26):
            if pos[j] != 0 and pos[j] != distance[j] + 1:
                return False
        return True


solution = Solution()
print(solution.checkDistances(s="abaccb",
                              distance=[1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]))
print(solution.checkDistances(s="aa",
                              distance=[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]))
