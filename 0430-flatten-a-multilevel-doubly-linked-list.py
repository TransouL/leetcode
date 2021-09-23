class Node:
    def __init__(self, val, prev=None, next=None, child=None):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child

    def __str__(self) -> str:
        return '%d -> %s' % (self.val, self.next)

    def __repr__(self) -> str:
        return '%d -> %s' % (self.val, self.next)


class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        if not head:
            return head
        curr = head
        while (True):
            if curr.child is not None:
                orig_next = curr.next
                child_last = curr.child
                while (child_last.next is not None):
                    child_last = child_last.next
                curr.next = curr.child
                curr.child.prev = curr
                curr.child = None
                child_last.next = orig_next
                if orig_next is not None:
                    orig_next.prev = child_last
            if not curr.next:
                break
            curr = curr.next
        return head


solution = Solution()
node1 = Node(1)
node2 = Node(2)
node3 = Node(3)
node1.next = node2
node1.child = node3
node2.prev = node1
print(solution.flatten(node1))
