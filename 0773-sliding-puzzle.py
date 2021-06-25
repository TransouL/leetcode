from collections import deque
from typing import List, Generator


class Solution:
    NEIGHBORS = [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]]

    def slidingPuzzle(self, board: List[List[int]]) -> int:
        def generate_next(status: str) -> Generator[str, None, None]:
            s = list(status)
            empty = s.index("0")
            for swap_to in Solution.NEIGHBORS[empty]:
                s[empty], s[swap_to] = s[swap_to], s[empty]
                yield "".join(s)
                s[empty], s[swap_to] = s[swap_to], s[empty]

        initStatus = "".join(str(x) for x in board[0] + board[1])

        if initStatus == "123450":
            return 0
        q = deque([(initStatus, 0)])
        visited = {initStatus}
        while q:
            status, steps = q.popleft()
            for next_status in generate_next(status):
                if next_status not in visited:
                    if next_status == "123450":
                        return steps + 1
                    q.append((next_status, steps + 1))
                    visited.add(next_status)

        return -1


solution = Solution()
print(solution.slidingPuzzle([[1, 2, 3], [4, 0, 5]]))
print(solution.slidingPuzzle([[1, 2, 3], [5, 4, 0]]))
print(solution.slidingPuzzle([[4, 1, 2], [5, 0, 3]]))
print(solution.slidingPuzzle([[3, 2, 4], [1, 5, 0]]))
print(solution.slidingPuzzle([[1, 2, 3], [4, 5, 0]]))
