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
    def __init__(self):
        self.preNode = None

    def inorder(self, node: TreeNode):
        if not node:
            return
        self.inorder(node.left)

        self.preNode.right = node
        node.left = None
        self.preNode = node

        self.inorder(node.right)

    def increasingBST(self, root: TreeNode) -> TreeNode:
        dummyNode = TreeNode
        self.preNode = dummyNode
        self.inorder(root)
        return dummyNode.right


solution = Solution()
print(solution.increasingBST(TreeNode(5, TreeNode(3, TreeNode(2, TreeNode(1)), TreeNode(4)),
                                      TreeNode(6, None, TreeNode(8, TreeNode(7), TreeNode(9))))))
print(solution.increasingBST(TreeNode(5, TreeNode(1), TreeNode(7))))

