from typing import List


class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        path, curr, levels = [label], label, 1
        while curr != 1:
            curr = curr // 2
            path.append(curr)
            levels += 1

        size, is_label_reverse = len(path), levels & 1 == 0
        start_path_index = -3 if is_label_reverse else -2
        level_left = 4 if is_label_reverse else 2
        for i in range(start_path_index, -size, -2):
            path[i] = level_left * 3 - 1 - path[i]
            level_left *= 4

        return path[::-1]


solution = Solution()
print(solution.pathInZigZagTree(14))  # [1,3,4,14]
print(solution.pathInZigZagTree(26))  # [1,2,6,10,26]
