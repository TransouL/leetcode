# from typing import List


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
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return list()
        node_queue = [root]
        result = list()
        while node_queue:
            level_size = len(node_queue)
            level_list = []
            for _ in range(level_size):
                node = node_queue.pop(0)
                level_list.append(node.val)
                if node.left:
                    node_queue.append(node.left)
                if node.right:
                    node_queue.append(node.right)
            result.append(level_list)
        return result
