from typing import List


class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        n = len(nums)
        flag1 = [-1] * n
        flag2 = [-1] * n
        for i in range(n):
            if nums[i] > 0 and flag1[i] == -1:
                flag1[i] = curr = i
                while True:
                    next = (curr + nums[curr]) % n
                    if next == curr:
                        break
                    if flag1[next] == i:
                        return True
                    elif flag1[next] != -1:
                        break
                    else:
                        if nums[next] > 0:
                            flag1[next] = i
                            curr = next
                        else:
                            break
            if nums[i] < 0 and flag2[i] == -1:
                flag2[i] = curr = i
                while True:
                    next = (curr + nums[curr]) % n
                    if next == curr:
                        break
                    if flag2[next] == i:
                        return True
                    elif flag2[next] != -1:
                        break
                    else:
                        if nums[next] < 0:
                            flag2[next] = i
                            curr = next
                        else:
                            break

        return False


solution = Solution()
print(solution.circularArrayLoop([2, -1, 1, 2, 2]))
print(solution.circularArrayLoop([-1, 2]))
print(solution.circularArrayLoop([-2, 1, -1, -2, -2]))
