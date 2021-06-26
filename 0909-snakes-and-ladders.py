from collections import deque
from typing import List, Generator


class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        def generate_next(status: int) -> Generator[int, None, None]:
            def getPosition(status: int):
                x = n - 1 - (status - 1) // n
                if (n - 1 - x) & 1 == 0:
                    y = (status - 1) % n
                else:
                    y = n - 1 - (status - 1) % n
                return x, y

            for i in range(1, 7):
                position = getPosition(status + i)
                if board[position[0]][position[1]] == -1:
                    yield status + i
                else:
                    yield board[position[0]][position[1]]

        n = len(board)
        q = deque([(1, 0)])
        visited = {1}
        while q:
            status, steps = q.popleft()
            for next_status in generate_next(status):
                if next_status == n * n:
                    return steps + 1
                if next_status not in visited:
                    q.append((next_status, steps + 1))
                    visited.add(next_status)

        return -1


solution = Solution()
print(solution.snakesAndLadders([
    [-1, -1, -1, -1, -1, -1],
    [-1, -1, -1, -1, -1, -1],
    [-1, -1, -1, -1, -1, -1],
    [-1, 35, -1, -1, 13, -1],
    [-1, -1, -1, -1, -1, -1],
    [-1, 15, -1, -1, -1, -1]]))
print(solution.snakesAndLadders([[-1, -1], [-1, 3]]))
print(solution.snakesAndLadders(
    [[-1, -1, 19, 10, -1], [2, -1, -1, 6, -1], [-1, 17, -1, 19, -1], [25, -1, 20, -1, -1], [-1, -1, -1, -1, 15]]
))
