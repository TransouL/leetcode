from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __str__(self) -> str:
        if not self.left and not self.right:
            return 'N(%d)' % self.val
        return 'N(%d, l: %s, r: %s)' % (self.val, self.left, self.right)

    def __repr__(self) -> str:
        return self.__str__()


class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        def dfs(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            triple = (node.val, dfs(node.left), dfs(node.right))
            if triple in seen:
                (tree, index) = seen[triple]
                repeat.add(tree)
                return index
            else:
                nonlocal idx
                idx += 1
                seen[triple] = (node, idx)
                return idx

        idx = 0
        seen = {}
        repeat = set()
        dfs(root)
        return list(repeat)


def loadBinaryTree(array: List) -> TreeNode:
    n, root = len(array), TreeNode(array[0])

    def loadNode(node: TreeNode, index: int) -> None:
        if index * 2 + 1 < n:
            node.left = None if array[index * 2 + 1] is None else TreeNode(array[index * 2 + 1])
            if node.left is not None:
                loadNode(node.left, index * 2 + 1)
        if index * 2 + 2 < n:
            node.right = None if array[index * 2 + 2] is None else TreeNode(array[index * 2 + 2])
            if node.right is not None:
                loadNode(node.right, index * 2 + 2)

    loadNode(root, 0)
    return root


solution = Solution()
root = loadBinaryTree([1, 2, 3, 4, None, 2, 4, None, None, 4])
print(solution.findDuplicateSubtrees(root))
root = loadBinaryTree([2, 1, 1])
print(solution.findDuplicateSubtrees(root))
