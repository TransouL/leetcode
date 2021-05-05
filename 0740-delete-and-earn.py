from typing import List


class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        values = {}
        for num in nums:
            values[num] = values.get(num, 0) + num
        values_sorted = sorted(values.items(), key=lambda item: item[0])

        prev, curr, curr_house = 0, 0, -1
        for house, value in values_sorted:
            if house == curr_house + 1:
                prev, curr, curr_house = curr, max(prev + value, curr), house
            else:
                prev, curr, curr_house = curr, curr + value, house
        return curr


solution = Solution()
print(solution.deleteAndEarn([3, 4, 2]))
print(solution.deleteAndEarn([2, 2, 3, 3, 3, 4]))
