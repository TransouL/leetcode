class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        nums = []
        while n > 0:
            nums.append(n % 10)
            n //= 10
        bits = len(nums)
        flags = [False] * bits

        def dfs(steps: int, curr: int) -> bool:
            if steps == 1 and curr == 0:
                return False
            if steps == bits:
                if curr & (curr - 1) == 0:
                    return True
                else:
                    return False
            for i, flag in enumerate(flags):
                if not flag and not (i > 0 and not flags[i - 1] and nums[i] == nums[i - 1]):
                    flags[i] = True
                    if dfs(steps + 1, curr * 10 + nums[i]):
                        return True
                    flags[i] = False
            return False

        return dfs(0, 0)


solution = Solution()
print(solution.reorderedPowerOf2(1))
print(solution.reorderedPowerOf2(10))
print(solution.reorderedPowerOf2(16))
print(solution.reorderedPowerOf2(24))
print(solution.reorderedPowerOf2(46))
print(solution.reorderedPowerOf2(56635))
