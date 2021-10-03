class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        n = len(s)
        ans = []
        group_count = 0
        for i in range(n - 1, -1, -1):
            if s[i] != '-':
                if group_count == k:
                    ans.append('-')
                    group_count = 0
                ans.append(s[i].upper())
                group_count += 1
        return "".join(ans[::-1])


solution = Solution()
print(solution.licenseKeyFormatting("5F3Z-2e-9-w", 4))
print(solution.licenseKeyFormatting("2-5g-3-J", 2))
print(solution.licenseKeyFormatting("--a-a-a-a--", 2))  # AA-AA
