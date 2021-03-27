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


class BSTIterator:
    def __init__(self, root: TreeNode):
        self.curr = root
        self.stack = list()

    def next(self) -> int:
        while self.curr:
            self.stack.append(self.curr)
            self.curr = self.curr.left
        curr = self.stack.pop()
        result = curr.val
        self.curr = curr.right
        return result

    def hasNext(self) -> bool:
        return self.curr is not None or len(self.stack) != 0


# bSTIterator = BSTIterator(TreeNode(7, TreeNode(3), TreeNode(15, TreeNode(9), TreeNode(20))))
# print(bSTIterator.next())
# print(bSTIterator.next())
# print(bSTIterator.hasNext())
# print(bSTIterator.next())
# print(bSTIterator.hasNext())
# print(bSTIterator.next())
# print(bSTIterator.hasNext())
# print(bSTIterator.next())
# print(bSTIterator.hasNext())
