from typing import List


class Solution:
    def compress(self, chars: List[str]) -> int:
        n = len(chars)
        write = left = 0
        for read in range(n):
            if read == n - 1 or chars[read] != chars[read + 1]:
                chars[write] = chars[read]
                write += 1
                count = read - left + 1
                if count > 1:
                    count_str = str(count)
                    for ch in count_str:
                        chars[write] = ch
                        write += 1
                left = read + 1

        return write



solution = Solution()
print(solution.compress(["a", "a", "b", "b", "c", "c", "c"]))
print(solution.compress(["a"]))
print(solution.compress(["a", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b"]))
