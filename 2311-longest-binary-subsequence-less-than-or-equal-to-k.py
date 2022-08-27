class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        n = len(s)
        sint = int(s, 2)
        if sint <= k:
            return n

        ans = s.count('0')
        kbin = bin(k)[2:]
        klen = len(kbin)
        target = s[n - klen:]
        ans += target.count('1')
        for i in range(klen):
            if kbin[i] != target[i]:
                if kbin[i] == '0':
                    ans -= 1
                break
        return ans


solution = Solution()
print(solution.longestSubsequence(s="1001010", k=5))
print(solution.longestSubsequence(s="00101001", k=1))
print(solution.longestSubsequence(
    s="111100010000011101001110001111000000001011101111111110111000011111011000010101110100110110001111001001011001010011010000011111101001101000000101101001110110000111101011000101",
    k=11713332))  # 96
print(solution.longestSubsequence(s="1", k=215358216))
