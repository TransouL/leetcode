from typing import List


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self) -> str:
        return '%d -> %s' % (self.val, self.next)

    def __repr__(self) -> str:
        return '%d -> %s' % (self.val, self.next)


class Solution:
    def splitListToParts(self, head: ListNode, k: int) -> List[ListNode]:
        if not head:
            return [None] * k
        all, curr, cnt = [head], head, 1
        while curr.next:
            all.append(curr.next)
            curr = curr.next
            cnt += 1
        if cnt < k:
            for _ in all:
                _.next = None
            return all + [None] * (k - cnt)
        else:
            ans = [None] * k
            part_len = cnt // k
            more_one = cnt % k
            for i in range(k):
                part_start_idx = part_len * i + (1 * min(i, more_one))
                ans[i] = all[part_start_idx]
                if part_start_idx != 0:
                    all[part_start_idx - 1].next = None
            return ans


solution = Solution()
node1 = ListNode(1, ListNode(2, ListNode(3, None)))
print(solution.splitListToParts(node1, 5))
node1 = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5, ListNode(6,
        ListNode(7, ListNode(8, ListNode(9, ListNode(10, None))))))))))
print(solution.splitListToParts(node1, 3))
node1 = None
print(solution.splitListToParts(node1, 3))