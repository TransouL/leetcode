from typing import List
bin = {'A': 0, 'C': 1, 'G': 2, 'T': 3}


class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        n = len(s)
        ans, stats = set(), set()
        x = 0
        for ch in s[:9]:
            x = (x << 2) | bin[ch]
        for i in range(n - 9):
            x = ((x << 2) | bin[s[i + 9]]) & ((1 << 20) - 1)
            if x in stats:
                ans.add(s[i: i + 10])
            else:
                stats.add(x)
        return list(ans)


solution = Solution()
print(solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"))
print(solution.findRepeatedDnaSequences("AAAAAAAAAAAAA"))
print(solution.findRepeatedDnaSequences("A"))
