# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self) -> str:
        return '%d -> %s' % (self.val, self.next)


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None
        pa, pb = headA, headB
        while pa != pb:
            pa = headB if pa is None else pa.next
            pb = headA if pb is None else pb.next
        return pa


solution = Solution()
node11 = ListNode(4)
node12 = ListNode(1)
node13 = ListNode(8)
node14 = ListNode(4)
node15 = ListNode(5)
node11.next = node12
node12.next = node13
node13.next = node14
node14.next = node15
node21 = ListNode(5)
node22 = ListNode(0)
node21.next = node22
node22.next = node12
print(solution.getIntersectionNode(node11, node21))
