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
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        result = 0
        def depth(node: TreeNode) -> int:
            if not node:
                return 0
            depth_l = depth(node.left)
            depth_r = depth(node.right)
            nonlocal result
            result = max(result, depth_l + depth_r)  # depth_l + depth_r + 1 - 1
            return max(depth_l, depth_r) + 1
        depth(root)
        return result
