# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        # 如果根节点是其中之一，则必然不是堂兄弟
        if root.val == x or root.val == y:
            return False

        found_first, first_parent, second_target = False, None, -1
        # 逐层查找，在同一层找到两个数则True；只找到一个数则False；都没找到则继续下一层
        curr_level = [root]
        while True:
            # 每一层查找每个节点的子节点，同时把子节点放入下一层
            next_level = []

            for node in curr_level:
                if node.left:
                    if not found_first:
                        if node.left.val == x:
                            found_first, first_parent = True, node
                            second_target = y
                        elif node.left.val == y:
                            found_first, first_parent = True, node
                            second_target = x
					# 这里else分支里只有if需要处理，两层合并写一个elif
                    elif node.left.val == second_target:
						# 在左子节点找到第二个数时，不需要判断是否是同一个父节点，直接可以确定是表兄弟
						return True
                    next_level.append(node.left)
                if node.right:
                    if not found_first:
                        if node.right.val == x:
                            # 因为在左子节点找到时不需要判断是否是同一个父节点，所以处理右子节点时不需要考虑父节点
                            found_first = True
                            second_target = y
                        elif node.right.val == y:
                            found_first = True
                            second_target = x
                    elif node.right.val == second_target:
						# 在右子节点找到第二个数时，可以确定结果了，此时需要判断是否是同一个父节点
						return first_parent != node
                    next_level.append(node.right)

            # 如果在这层只找到了一个数，说明不在同一层，不是表兄弟；如果没找到，则继续下一层查找
            if found_first: return False
            curr_level = next_level

        # 不会走到这里
        # return False


solution = Solution()
print(solution.isCousins(TreeNode(1, TreeNode(2, TreeNode(4)), TreeNode(3)), 4, 3))
print(solution.isCousins(TreeNode(1, TreeNode(2, None, TreeNode(4)), TreeNode(3, None, TreeNode(5))), 5, 4))
print(solution.isCousins(TreeNode(1, TreeNode(2, None, TreeNode(4)), TreeNode(3)), 2, 3))
