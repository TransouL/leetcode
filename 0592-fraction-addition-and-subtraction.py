class Solution:
    def fractionAddition(self, expression: str) -> str:
        leastCommon = 2520
        total = 0
        up, down = 0, 0
        upOrDwon = True
        minus = False
        for ch in expression:
            if ch == '/':
                upOrDwon = False
            elif ch == '-':
                if down != 0:
                    if minus:
                        total -= up * leastCommon // down
                    else:
                        total += up * leastCommon // down
                minus, upOrDwon, up, down = True, True, 0, 0
            elif ch == '+':
                if minus:
                    total -= up * leastCommon // down
                else:
                    total += up * leastCommon // down
                minus, upOrDwon, up, down = False, True, 0, 0
            else:
                if upOrDwon:
                    up = up * 10 + ord(ch) - ord('0')
                else:
                    down = down * 10 + ord(ch) - ord('0')
        if minus:
            total -= up * leastCommon // down
        else:
            total += up * leastCommon // down

        if total == 0:
            return "0/1"
        for i in [7, 5, 3, 3, 2, 2, 2]:
            if total % i == 0:
                total //= i
                leastCommon //= i
        return str(total) + '/' + str(leastCommon)


solution = Solution()
print(solution.fractionAddition("-1/2+1/2"))
print(solution.fractionAddition("-1/2+1/2+1/3"))
print(solution.fractionAddition("1/3-1/2"))
print(solution.fractionAddition("5/3+1/3"))  # "2/1"
