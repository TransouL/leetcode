class Solution:
    def minimumNumbers(self, num: int, k: int) -> int:
        if num == 0:
            return 0
        if num % 2 == 1 and k % 2 == 0:
            return -1
        for i in range(1, 11):
            if num % 10 == k * i % 10:
                if k * i <= num:
                    return i
                else:
                    return -1
        return -1


solution = Solution()
print(solution.minimumNumbers(num=58, k=9))
print(solution.minimumNumbers(num=37, k=2))
print(solution.minimumNumbers(num=0, k=7))
print(solution.minimumNumbers(num=20, k=2))
print(solution.minimumNumbers(num=1, k=5))
