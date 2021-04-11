class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        # return bin(x ^ y).count('1')
        xor = x ^ y
        result = 0
        while xor:
            if xor & 1:
                result += 1
            xor = xor >> 1
        return result

