COUNT_AND_SAY = ["1"]
CNT = 1


class Solution:
    def countAndSay(self, n: int) -> str:
        global CNT
        if n <= CNT:
            return COUNT_AND_SAY[n - 1]
        for i in range(n - CNT):
            str_last = COUNT_AND_SAY[-1]
            str_curr = []
            ch_count = 0
            ch_last = str_last[0]
            for ch in str_last:
                if ch == ch_last:
                    ch_count += 1
                else:
                    str_curr.append(str(ch_count))
                    str_curr.append(ch_last)
                    ch_count = 1
                    ch_last = ch
            str_curr.append(str(ch_count))
            str_curr.append(ch_last)
            CNT += 1
            COUNT_AND_SAY.append("".join(str_curr))

        return COUNT_AND_SAY[-1]


solution = Solution()
print(solution.countAndSay(1))
print(solution.countAndSay(4))
print(solution.countAndSay(30))
