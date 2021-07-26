class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        if not root or not root.left:
            return -1
        if root.left.val != root.right.val:
            max_value = max(root.left.val, root.right.val)
            min_node = root.left if root.left.val < root.right.val else root.right
            min_node_sec_min_value = self.findSecondMinimumValue(min_node)
            if min_node_sec_min_value == -1:
                return max_value
            else:
                return min(min_node_sec_min_value, max_value)
        else:
            left = self.findSecondMinimumValue(root.left)
            right = self.findSecondMinimumValue(root.right)
            if left == right:
                return -1
            else:
                if left == -1:
                    return right
                if right == -1:
                    return left
                return min(left, right)

