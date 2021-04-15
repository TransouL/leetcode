# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# 
#     def __str__(self) -> str:
#         if self.left is None and self.right is None:
#             return '%d ()' % self.val
#         return '%d (%s, %s)' % (self.val, self.left, self.right)


class Solution:
    def inorderTraversal(self, root: TreeNode) -> list:
        if not root:
            return list()
        result = self.inorderTraversal(root.left)
        result.append(root.val)
        result.extend(self.inorderTraversal(root.right))
        return result
