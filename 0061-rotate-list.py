# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# 
#     def __str__(self) -> str:
#         return '%d -> %s' % (self.val, self.next)


class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head or not head.next or k == 0:
            return head
        curr = head
        count = 1
        while curr.next:
            curr = curr.next
            count += 1
        offset = count - (k % count)
        if offset == count:
            return head
        curr.next = head # curr is the tail now
        for _ in range(offset):
            curr = curr.next
        result = curr.next
        curr.next = None
        return result

