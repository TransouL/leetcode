from typing import Optional


class Solution:

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        inorderList = []

        def inorderTraversal(node: TreeNode) -> None:
            if not node or len(inorderList) >= k:
                return
            inorderTraversal(node.left)
            inorderList.append(node.val)
            inorderTraversal(node.right)

        inorderTraversal(root)
        return inorderList[k - 1]
