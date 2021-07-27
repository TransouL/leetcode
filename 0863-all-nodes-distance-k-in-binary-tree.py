from typing import List


class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        ans, linked, found = [], [], False

        def dfs(curr: TreeNode) -> bool:
            if curr != target:
                linked.append(curr)
                left = right = False
                if curr.left is not None:
                    left = dfs(curr.left)
                if curr.right is not None:
                    right = dfs(curr.right)
                if left or right:
                    return True
                else:
                    linked.pop()
                    return False
            else:
                return True

        def down(curr: TreeNode, leftSteps: int) -> None:
            if leftSteps == 0:
                ans.append(curr.val)
                return
            else:
                if curr.left is not None and curr.left.val != -1:
                    down(curr.left, leftSteps - 1)
                if curr.right is not None and curr.right.val != -1:
                    down(curr.right, leftSteps - 1)

        def up() -> None:
            nonlocal k
            while linked:
                lastNode = linked.pop()
                k -= 1
                if k > 0:
                    down(lastNode, k)
                    lastNode.val = -1
                elif k == 0:
                    ans.append(lastNode.val)
                else:
                    break

        dfs(root)
        down(target, k)
        target.val = -1
        up()
        return ans

