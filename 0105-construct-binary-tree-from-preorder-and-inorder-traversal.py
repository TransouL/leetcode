# from typing import List
# 
# 
# # Definition for a binary tree node.
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
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        inorder_mapping = {element: index for index, element in enumerate(inorder)}

        def build(preorder_l: int, preorder_r: int, inorder_l: int, inorder_r: int):
            if preorder_l > preorder_r:
                return None
            preorder_root_index = preorder_l
            inorder_root_index = inorder_mapping[preorder[preorder_root_index]]
            size_left_subtree = inorder_root_index - inorder_l
            return TreeNode(preorder[preorder_root_index],
                            build(preorder_l + 1, preorder_l + size_left_subtree, inorder_l, inorder_root_index - 1),
                            build(preorder_l + size_left_subtree + 1, preorder_r, inorder_root_index + 1, inorder_r))

        n = len(preorder)
        return build(0, n - 1, 0, n - 1)

