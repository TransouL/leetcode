class Solution:
    def frequencySort(self, s: str) -> str:
        counter = {}.fromkeys(s, 0)
        maxFreq = 0
        for ch in s:
            counter[ch] += 1
            maxFreq = max(maxFreq,  counter[ch] )

        count_list = [[] for _ in range(maxFreq + 1)]
        for ch, count in counter.items():
            count_list[count].append(ch)

        ans = ""
        for i in range(maxFreq, 0, -1):
            for ch in count_list[i]:
                ans += ch * i

        return ans


solution = Solution()
print(solution.frequencySort("tree"))
print(solution.frequencySort("cccaaa"))
print(solution.frequencySort("Aabb"))