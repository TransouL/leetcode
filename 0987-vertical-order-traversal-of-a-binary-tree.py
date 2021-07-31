from collections import defaultdict
from typing import List


class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        def dfs(node: TreeNode, row, col) -> None:
            nodes.append((col, row, node.val))
            if node.left is not None:
                dfs(node.left, row + 1, col - 1)
            if node.right is not None:
                dfs(node.right, row + 1, col + 1)

        nodes = []
        dfs(root, 0, 0)
        nodes.sort()
        ans, prev_col = [], 1000
        for col, row, val in nodes:
            if col == prev_col:
                ans[-1].append(val)
            else:
                ans.append([val])
                prev_col = col
        return ans

