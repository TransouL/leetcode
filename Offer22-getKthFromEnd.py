# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self) -> str:
        return '%d -> %s' % (self.val, self.next)


class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        cache = [None] * k
        i, curr = 0, head
        while curr.next is not None:
            cache[i] = curr
            curr = curr.next
            i = 0 if i == k - 1 else i + 1
        return curr if k == 1 else cache[(i + 1) % k]


solution = Solution()
node1 = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5, None)))))
print(solution.getKthFromEnd(node1, 2))
