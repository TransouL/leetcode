from collections import deque
from typing import List, Generator


class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        if target == "0000":
            return 0
        if "0000" in deadends:
            return -1

        def num_prev(x: str) -> str:
            return "9" if x == "0" else str(int(x) - 1)

        def num_next(x: str) -> str:
            return "0" if x == "9" else str(int(x) + 1)

        def generate_next(status: str) -> Generator[str, None, None]:
            s = list(status)
            for i in range(4):
                num = s[i]
                s[i] = num_prev(num)
                yield "".join(s)
                s[i] = num_next(num)
                yield "".join(s)
                s[i] = num

        dead = set(deadends)
        q = deque([("0000", 0)])
        visited = {"0000"}
        while q:
            status, step = q.popleft()
            for next_status in generate_next(status):
                if next_status == target:
                    return step + 1
                if next_status not in visited and next_status not in dead:
                    q.append((next_status, step + 1))
                    visited.add(next_status)

        return -1


solution = Solution()
print(solution.openLock(["0201", "0101", "0102", "1212", "2002"], "0202"))
print(solution.openLock(["8888"], "0009"))
print(solution.openLock(["8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"], "8888"))
print(solution.openLock(["0000"], "8888"))
print(solution.openLock(["8887", "8889", "8788", "8988", "7888", "9888"], "8888"))
print(solution.openLock(["8889", "8898", "8988", "9888"], "8888"))
print(solution.openLock(["8889", "8878", "8898", "8788", "8988", "7888", "9888"], "8888"))
