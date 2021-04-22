# Definition for a binary tree node.
from typing import List

# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# 
#     def __str__(self) -> str:
#         if not self.left and not self.right:
#             return '%d ()' % self.val
#         return '%d (%s, %s)' % (self.val, self.left, self.right)


class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return list()
        result = [root.val]
        result.extend(self.preorderTraversal(root.left))
        result.extend(self.preorderTraversal(root.right))
        return result
