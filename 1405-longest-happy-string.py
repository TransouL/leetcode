class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        ans, cnt, notTriple, tripleChar = [], [a, b, c], False, ''
        while True:
            found, maxCnt = False, max(cnt)
            for i in range(3):
                if cnt[i] != 0:
                    ch = chr(ord('a') + i)
                    if notTriple:
                        if ch != tripleChar:
                            ans += ch
                            cnt[i] -= 1
                            found = True
                            notTriple = False
                            break
                    elif cnt[i] == maxCnt:
                        ans += ch
                        cnt[i] -= 1
                        found = True
                        if len(ans) < 2 or ans[-1] != ch or ans[-2] != ch:
                            notTriple = False
                        else:
                            notTriple = True
                            tripleChar = ch
                        break
            if not found:
                break
        return "".join(ans)


solution = Solution()
print(solution.longestDiverseString(a=1, b=1, c=7))
print(solution.longestDiverseString(a=2, b=2, c=1))
print(solution.longestDiverseString(a=7, b=1, c=0))
print(solution.longestDiverseString(a=1, b=0, c=3))
print(solution.longestDiverseString(a=5, b=4, c=3))
