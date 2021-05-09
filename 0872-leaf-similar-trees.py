from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __str__(self) -> str:
        if not self.left and not self.right:
            return '%d ()' % self.val
        return '%d (%s, %s)' % (self.val, self.left, self.right)


class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        def preorder(node: TreeNode, leaves: List[int]) -> None:
            if not node:
                return
            if node.left is None and node.right is None:
                leaves.append(node.val)
                return
            preorder(node.left, leaves)
            preorder(node.right, leaves)

        leaves1, leaves2 = [], []
        preorder(root1, leaves1)
        preorder(root2, leaves2)
        return leaves1 == leaves2


solution = Solution()
print(solution.leafSimilar(
    TreeNode(3, TreeNode(5, TreeNode(6), TreeNode(2, TreeNode(7), TreeNode(4))), TreeNode(1, TreeNode(9), TreeNode(8))),
    TreeNode(3, TreeNode(5, TreeNode(6), TreeNode(7)),
             TreeNode(1, TreeNode(4), TreeNode(2, TreeNode(9), TreeNode(8))))))
print(solution.leafSimilar(TreeNode(1), TreeNode(1)))
print(solution.leafSimilar(TreeNode(1), TreeNode(2)))
print(solution.leafSimilar(TreeNode(1, TreeNode(2)), TreeNode(2, None, TreeNode(2))))
print(solution.leafSimilar(TreeNode(1, TreeNode(2), TreeNode(3)), TreeNode(1, TreeNode(3), TreeNode(2))))

