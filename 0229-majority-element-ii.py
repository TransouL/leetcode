from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        cand1 = cand2 = vote1 = vote2 = cnt1 = cnt2 = 0
        for num in nums:
            if vote1 > 0 and num == cand1:
                vote1 += 1
            elif vote2 > 0 and num == cand2:
                vote2 += 1
            elif vote1 == 0:
                cand1 = num
                vote1 += 1
            elif vote2 == 0:
                cand2 = num
                vote2 += 1
            else:
                vote1 -= 1
                vote2 -= 1

        for num in nums:
            if vote1 > 0 and num == cand1:
                cnt1 += 1
            elif vote2 > 0 and num == cand2:
                cnt2 += 1
        ans, threshold = [], len(nums) // 3
        if cnt1 > threshold:
            ans.append(cand1)
        if cnt2 > threshold:
            ans.append(cand2)

        return ans


solution = Solution()
print(solution.majorityElement([3, 2, 3]))
print(solution.majorityElement([1]))
print(solution.majorityElement([1, 1, 1, 3, 3, 2, 2, 2]))
