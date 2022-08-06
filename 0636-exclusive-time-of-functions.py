from typing import List


class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        ans = [0] * n
        stackId = []
        stackStart = []
        callOther = [0]
        for log in logs:
            parts = log.split(":")
            id, timestamp = int(parts[0]), int(parts[2])
            if parts[1] == "start":
                stackId.append(id)
                stackStart.append(timestamp)
                callOther.append(0)
            else:
                duration = timestamp - stackStart[-1] + 1 - callOther[-1]
                ans[id] += duration
                stackId.pop()
                stackStart.pop()
                other = callOther.pop()
                callOther[-1] += duration + other
        return ans


solution = Solution()
print(solution.exclusiveTime(n=2, logs=["0:start:0", "1:start:2", "1:end:5", "0:end:6"]))
print(solution.exclusiveTime(n=1, logs=["0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"]))
print(solution.exclusiveTime(n=2, logs=["0:start:0", "0:start:2", "0:end:5", "1:start:6", "1:end:6", "0:end:7"]))
print(solution.exclusiveTime(n=2, logs=["0:start:0", "0:start:2", "0:end:5", "1:start:7", "1:end:7", "0:end:8"]))
print(solution.exclusiveTime(n=1, logs=["0:start:0", "0:end:0"]))
print(solution.exclusiveTime(n=1, logs=["0:start:0","0:start:1","0:start:2","0:end:3","0:end:4","0:end:5"]))
