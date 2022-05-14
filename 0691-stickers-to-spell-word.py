from typing import List
from collections import Counter
from functools import lru_cache

class Solution:
    def minStickers(self, stickers: List[str], target: str) -> int:
        @lru_cache(maxsize=None)
        def dp(mask: int) -> int:
            if mask == 0:
                return 0
            res = m + 1
            for sticker in stickers:
                left = mask
                cnt = Counter(sticker)
                for i, c in enumerate(target):
                    if mask >> i & 1 and cnt[c]:
                        cnt[c] -= 1
                        left ^= 1 << i
                if left < mask:
                    res = min(res, dp(left) + 1)
            return res

        m = len(target)
        ans = dp((1 << m) - 1)
        return ans if ans <= m else -1


solution = Solution()
print(solution.minStickers(stickers=["with", "example", "science"], target="thehat"))
print(solution.minStickers(stickers=["notice", "possible"], target="basicbasic"))
print(solution.minStickers(
    stickers=["control", "heart", "interest", "stream", "sentence", "soil", "wonder", "them", "month", "slip", "table",
              "miss", "boat", "speak", "figure", "no", "perhaps", "twenty", "throw", "rich", "capital", "save",
              "method", "store", "meant", "life", "oil", "string", "song", "food", "am", "who", "fat", "if", "put",
              "path", "come", "grow", "box", "great", "word", "object", "stead", "common", "fresh", "the", "operate",
              "where", "road", "mean"], target="stoodcrease"))
