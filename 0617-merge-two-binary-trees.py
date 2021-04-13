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
    def mergeTrees(self, root1: TreeNode, root2: TreeNode) -> TreeNode:
        if root1 is None:
            return root2
        elif root2 is None:
            return root1
        merged_left = self.mergeTrees(root1.left, root2.left)
        merged_right = self.mergeTrees(root1.right, root2.right)
        return TreeNode(root1.val + root2.val, merged_left, merged_right)