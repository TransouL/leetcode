from typing import List
import heapq
from collections import Counter


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        words_count = Counter()
        for word in words:
            words_count[word] += 1
        # 因为相同频率要按字母顺序，所以把key反过来，用nsmallest来找最多的k个
        return list(map(lambda x: x[0], heapq.nsmallest(k, words_count.items(), key=lambda x: (-x[1], x[0]))))


solution = Solution()
print(solution.topKFrequent(["i", "love", "leetcode", "i", "love", "coding"], 2))
print(solution.topKFrequent(["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], 4))
print(solution.topKFrequent(["i", "love", "leetcode", "i", "love", "coding"], 3))
