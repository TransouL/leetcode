import re
from collections import deque
from itertools import product


class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        def clean(s):
            n = 1
            while n:
                s, n = re.subn(r"(.)\1{2,}", "", s)
            return s

        hand = "".join(sorted(hand))
        queue = deque([(board, hand, 0)])
        visited = {(board, hand)}
        while queue:
            curr_board, curr_hand, step = queue.popleft()
            for i, j in product(range(len(curr_board) + 1), range(len(curr_hand))):
                if j > 0 and curr_hand[j] == curr_hand[j - 1]:
                    continue
                if i > 0 and curr_board[i - 1] == curr_hand[j]:
                    continue
                if (i < len(curr_board) and curr_board[i] == curr_hand[j]) or \
                        (0 < i < len(curr_board) and curr_board[i - 1] == curr_board[i]
                         and curr_board[i - 1] != curr_hand[j]):
                    new_board = clean(curr_board[:i] + curr_hand[j] + curr_board[i:])
                    new_hand = curr_hand[:j] + curr_hand[j + 1:]
                    if not new_board:
                        return step + 1
                    if (new_board, new_hand) not in visited:
                        queue.append((new_board, new_hand, step + 1))
                        visited.add((new_board, new_hand))

        return -1


solution = Solution()
print(solution.findMinStep(board="WRRBBW", hand="RB"))
print(solution.findMinStep(board="WWRRBBWW", hand="WRBRW"))
print(solution.findMinStep(board="G", hand="GGGGG"))
print(solution.findMinStep(board="RBYYBBRRB", hand="YRBGB"))
print(solution.findMinStep(board="RRWWRRBBRR", hand="WB"))
