from collections import defaultdict


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
    def pathSum(self, root: TreeNode, targetSum: int) -> int:
        prefix = defaultdict(int)
        prefix[0] = 1

        def dfs(node: TreeNode, curr: int) -> int:
            if not node:
                return 0

            res = 0
            curr += node.val
            res += prefix[curr - targetSum]
            prefix[curr] += 1
            res += dfs(node.left, curr)
            res += dfs(node.right, curr)
            prefix[curr] -= 1

            return res

        return dfs(root, 0)
