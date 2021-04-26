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
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        if not root:
            return 0
        if root.val > high:
            return self.rangeSumBST(root.left, low, high)
        if root.val < low:
            return self.rangeSumBST(root.right, low, high)
        return root.val + self.rangeSumBST(root.right, low, high) + self.rangeSumBST(root.left, low, high)


solution = Solution()
print(solution.rangeSumBST(TreeNode(10, TreeNode(5, TreeNode(3), TreeNode(7)),
                                    TreeNode(15, None, TreeNode(18))), 7, 15))
print(solution.rangeSumBST(TreeNode(10, TreeNode(5, TreeNode(3, TreeNode(1)), TreeNode(7, TreeNode(6))),
                                    TreeNode(15, TreeNode(13), TreeNode(18))), 6, 10))
