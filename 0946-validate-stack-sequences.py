from typing import List


class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        n = len(pushed)
        stack = []
        i, j = 0, 0
        while i < n:
            if pushed[i] == popped[j]:
                i += 1
                j += 1
            elif popped[j] not in stack:
                stack.append(pushed[i])
                i += 1
            else:
                if popped[j] == stack[-1]:
                    stack.pop()
                    j += 1
                else:
                    return False
        for k in range(j, n):
            if popped[k] == stack[-1]:
                stack.pop()
            else:
                return False
        return True


solution = Solution()
print(solution.validateStackSequences(pushed=[1, 2, 3, 4, 5], popped=[4, 5, 3, 2, 1]))
print(solution.validateStackSequences(pushed=[1, 2, 3, 4, 5], popped=[4, 3, 5, 1, 2]))
