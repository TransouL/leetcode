from typing import List


class Solution:
    def maxLength(self, arr: List[str]) -> int:
        ans = 0
        possible_masks = [0]
        for s in arr:
            mask = 0
            for ch in s:
                idx = ord(ch) - ord('a')
                if (mask >> idx) & 1:
                    mask = 0
                    break
                mask |= 1 << idx
            if mask == 0:
                continue

            for possible_mask in possible_masks:
                if possible_mask & mask == 0:
                    mask_new = possible_mask | mask
                    possible_masks.append(mask_new)
                    ans = max(ans, bin(mask_new).count('1'))

        return ans


solution = Solution()
print(solution.maxLength(["un", "iq", "ue"]))
print(solution.maxLength(["cha", "r", "act", "ers"]))
print(solution.maxLength(["abcdefghijklmnopqrstuvwxyz"]))
