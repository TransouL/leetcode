class MyHashMap:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.__nums = [-1] * 1000001
        # self.__nums = [False for i in range(1000001)]

    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        self.__nums[key] = value

    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        return self.__nums[key]

    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        self.__nums[key] = -1


# Your MyHashMap object will be instantiated and called as such:
# myHashMap = MyHashMap()
# myHashMap.put(1, 1)
# myHashMap.put(2, 2)
# print(myHashMap.get(1))
# print(myHashMap.get(3))
# myHashMap.put(2, 1)
# print(myHashMap.get(2))
# myHashMap.remove(2)
# print(myHashMap.get(2))
