from bisect import bisect_left
from collections import defaultdict
from typing import List


class Solution:
    def minAbsoluteSumDiff(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        nums1_stats = [False] * 100001
        abs_diff = [0] * n
        abs_diff_stats = defaultdict(list)
        ans = 0
        for i in range(n):
            diff = abs(nums1[i] - nums2[i])
            abs_diff[i] = diff
            ans += diff
            nums1_stats[nums1[i]] = True
            if diff != 0:
                abs_diff_stats[diff].append(i)

        sorted1 = []
        for i in range(100000):
            if nums1_stats[i]:
                sorted1.append(i)
        sorted1_len = len(sorted1)

        enhance = 0
        for diff, index_list in sorted(abs_diff_stats.items(), reverse=True):
            if enhance >= diff:
                break

            for index in index_list:
                left_pos = bisect_left(sorted1, nums2[index])
                if left_pos < sorted1_len:
                    if sorted1[left_pos] == nums2[index]:
                        return (ans - diff) % 1000000007
                    else:
                        if left_pos != 0:
                            enhance = max(enhance, abs_diff[index] - (nums2[index] - sorted1[left_pos - 1]))
                        enhance = max(enhance, abs_diff[index] - (sorted1[left_pos] - nums2[index]))
                else:
                    enhance = max(enhance, sorted1[-1] - nums1[index])

        return (ans - enhance) % 1000000007


solution = Solution()
print(solution.minAbsoluteSumDiff([1, 7, 5], [2, 3, 5]))
print(solution.minAbsoluteSumDiff([2, 4, 6, 8, 10], [2, 4, 6, 8, 10]))
print(solution.minAbsoluteSumDiff([1, 10, 4, 4, 2, 7], [9, 3, 5, 1, 7, 4]))

