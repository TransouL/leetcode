# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# 
#     def __str__(self) -> str:
#         return '%d -> %s' % (self.val, self.next)


class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        if left == right:
            return head
        dummy_node = ListNode(-1, head)
        pre = dummy_node
        for _ in range(left - 1):
            pre = pre.next
        curr = pre.next
        for _ in range(left, right):
            next = curr.next
            curr.next = next.next
            next.next = pre.next
            pre.next = next
        return dummy_node.next


# solution = Solution()
# node1 = ListNode(1)
# node2 = ListNode(2)
# node3 = ListNode(3)
# node4 = ListNode(4)
# node5 = ListNode(5)
# node1.next = node2
# node2.next = node3
# node3.next = node4
# node4.next = node5
# print(node1)
# print(solution.reverseBetween(node1, 2, 4))
# 
# node1.next = node2
# node2.next = None
# print(node1)
# print(solution.reverseBetween(node1, 1, 1))
# print(solution.reverseBetween(node1, 1, 2))
# 
# node1.next = None
# print(node1)
# print(solution.reverseBetween(node1, 1, 1))
