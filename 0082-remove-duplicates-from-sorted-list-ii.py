# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# 
#     def __str__(self) -> str:
#         return '%d -> %s' % (self.val, self.next)


class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or head.next is None:
            return head
        dummy_node = ListNode(-1, head)
        pre = dummy_node
        while pre.next and pre.next.next:
            if pre.next.val == pre.next.next.val:
                duplicate_value = pre.next.val
                pre.next = pre.next.next
                while pre.next and pre.next.val == duplicate_value:
                    pre.next = pre.next.next
            else:
                pre = pre.next
        return dummy_node.next


# solution = Solution()
# node1 = ListNode(1)
# node2 = ListNode(2)
# node3 = ListNode(3)
# node4 = ListNode(3)
# node5 = ListNode(4)
# node6 = ListNode(4)
# node7 = ListNode(5)
# node1.next = node2
# node2.next = node3
# node3.next = node4
# node4.next = node5
# node5.next = node6
# node6.next = node7
# print(node1)
# print(solution.deleteDuplicates(node1))
# 
# node1 = ListNode(1)
# node2 = ListNode(1)
# node3 = ListNode(1)
# node4 = ListNode(2)
# node5 = ListNode(3)
# node1.next = node2
# node2.next = node3
# node3.next = node4
# node4.next = node5
# print(node1)
# print(solution.deleteDuplicates(node1))
# 
# node1.next = None
# print(node1)
# print(solution.deleteDuplicates(node1))
