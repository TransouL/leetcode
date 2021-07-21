# Definition for singly-linked list.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

    def __str__(self) -> str:
        return '%d (%d) -> %s' % (self.val, -1 if not self.random else self.random.val, self.next)


class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None

        node = head
        while node:
            node_new = Node(node.val)
            node_new.next = node.next
            node.next = node_new
            node = node_new.next

        node = head
        while node:
            if node.random:
                node.next.random = node.random.next
            node = node.next.next

        node = head
        while node:
            node_new, node = node.next, node.next.next
            node_new.next = node_new.next.next if node_new.next is not None else None

        return head.next


solution = Solution()
node4 = Node(1, None)
node3 = Node(10, node4)
node2 = Node(11, node3)
node1 = Node(13, node2)
node0 = Node(7, node1)
node1.random = node0
node2.random = node4
node3.random = node2
node4.random = node0
print(node0)
print(solution.copyRandomList(node0))
