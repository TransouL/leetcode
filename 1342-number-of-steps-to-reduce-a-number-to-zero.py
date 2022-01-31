class Solution:
    def numberOfSteps(self, num: int) -> int:
        numb = bin(num)
        # 等于二进制位数 - 1(除最高位，每一位需要除一次2) 加上 二进制里1的数量(每个1代表会出现一次奇数)
        # 例如：14 -> 0b1110，123 -> 0b1111011    注意要把0b的两位减掉
        return len(numb) + numb.count('1') - 3


solution = Solution()
print(solution.numberOfSteps(14))
print(solution.numberOfSteps(8))
print(solution.numberOfSteps(123))
