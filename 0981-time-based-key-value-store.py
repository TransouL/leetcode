from collections import defaultdict


class TimeMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.data[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        length = len(self.data[key])
        if length == 0 or self.data[key][0][0] > timestamp:
            return ""

        def binsearch() -> int:
            low, high = 0, length - 1
            while low < high:
                mid = low + (high - low) // 2
                if self.data[key][mid][0] < timestamp:
                    low = mid + 1
                else:
                    high = mid
            return low if self.data[key][low][0] <= timestamp else low - 1

        index = binsearch()
        return self.data[key][index][1]


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)

# case 1
# ops = ["TimeMap", "set", "get", "get", "set", "get", "get"]
# data = [[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]

# case 2
ops = ["TimeMap", "set", "set", "get", "get", "get", "get", "get"]
data = [[], ["love", "high", 10], ["love", "low", 20], ["love", 5], ["love", 10], ["love", 15], ["love", 20],
        ["love", 25]]

obj = None
for i in range(len(ops)):
    if ops[i] == 'TimeMap':
        obj = TimeMap()
        print(None)
    elif ops[i] == 'set':
        print(obj.set(data[i][0], data[i][1], data[i][2]))
    elif ops[i] == 'get':
        print(obj.get(data[i][0], data[i][1]))
