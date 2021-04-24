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
    def inorderTraversal(self, node: TreeNode):
        if not node:
            return
        self.inorderTraversal(node.left)
        if self.pre:
            self.minDiff = min(node.val - self.pre.val, self.minDiff)
        self.pre = node
        self.inorderTraversal(node.right)

    def minDiffInBST(self, root: TreeNode):
        self.pre = None
        self.minDiff = 10e6
        self.inorderTraversal(root)
        return self.minDiff


solution = Solution()
print(solution.minDiffInBST(TreeNode(4, TreeNode(2, TreeNode(1), TreeNode(3)), TreeNode(6))))
print(solution.minDiffInBST(TreeNode(1, TreeNode(0), TreeNode(48, TreeNode(12), TreeNode(49)))))
print(solution.minDiffInBST(TreeNode(8, TreeNode(0), TreeNode(30, TreeNode(14), TreeNode(49)))))
