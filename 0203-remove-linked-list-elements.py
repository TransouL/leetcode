# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self) -> str:
        return '%d -> %s' % (self.val, self.next)


class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if not head:
            return head
        dummy = curr = ListNode(-1, head)
        while curr.next is not None:
            if curr.next.val != val:
                curr = curr.next
            else:
                curr.next = curr.next.next
        return dummy.next


solution = Solution()
node1 = ListNode(1, ListNode(2, ListNode(6, ListNode(3, ListNode(4, ListNode(5, ListNode(6, None)))))))
print(solution.removeElements(node1, 6))
node2 = None
print(solution.removeElements(node2, 6))
node3 = ListNode(7, ListNode(7, ListNode(7, ListNode(7, None))))
print(solution.removeElements(node3, 7))
