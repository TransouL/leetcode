# Definition for a binary tree node.
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
    def isSymmetric(self, root: TreeNode) -> bool:
        def check(node1: TreeNode, node2: TreeNode):
            if not node1 and not node2:
                return True
            if not node1 or not node2:
                return False
            return node1.val == node2.val and check(node1.left, node2.right) and check(node1.right, node2.left)
        return check(root, root)
