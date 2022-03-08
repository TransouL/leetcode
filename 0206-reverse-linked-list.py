# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self) -> str:
        return '%d -> %s' % (self.val, self.next)


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev, curr = None, head
        while curr is not None:
            curr.next, curr, prev = prev, curr.next, curr
        return prev


solution = Solution()
node1 = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5, None)))))
print(solution.reverseList(node1))
