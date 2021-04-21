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
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root:
            self.flatten(root.right)
            if root.left:
                self.flatten(root.left)
                if not root.right:
                    root.right, root.left = root.left, None
                else:
                    link_node = root.left
                    while link_node.right:
                        link_node = link_node.right
                    link_node.right, root.right, root.left = root.right, root.left, None
