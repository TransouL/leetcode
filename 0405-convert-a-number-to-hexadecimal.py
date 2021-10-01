MOD = 2 ** 32
HEX = {10: 'a', 11: 'b', 12: 'c', 13: 'd', 14: 'e', 15: 'f'}


class Solution:
    def toHex(self, num: int) -> str:
        if num == 0:
            return "0"
        num = num if num > 0 else MOD + num
        ans = []
        while num > 0:
            last4 = num & 0b1111
            ans.append(HEX.get(last4) if last4 > 9 else str(last4))
            num = num >> 4
        return "".join(ans[::-1])


solution = Solution()
print(solution.toHex(26))
print(solution.toHex(-1))
print(solution.toHex(0))
