class Solution:
    def reformat(self, s: str) -> str:
        nums, letters = [], []
        for ch in s:
            if ch.isdigit():
                nums.append(ch)
            else:
                letters.append(ch)

        nl, ll = len(nums), len(letters)
        if nl > ll + 1 or ll > nl + 1:
            return ""
        hasLast = nl == ll + 1
        if ll == nl + 1:
            nums, letters, hasLast = letters, nums, True
        ans = []
        for i in range(len(letters)):
            ans.append(nums[i])
            ans.append(letters[i])
        if hasLast:
            ans.append(nums[-1])
        return "".join(ans)


solution = Solution()
print(solution.reformat("a0b1c2"))
print(solution.reformat("leetcode"))
print(solution.reformat("1229857369"))
print(solution.reformat("covid2019"))
print(solution.reformat("ab123"))
