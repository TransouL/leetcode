class MyHashSet:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.__nums = [False] * 1000001

    def add(self, key: int) -> None:
        self.__nums[key] = True

    def remove(self, key: int) -> None:
        self.__nums[key] = False

    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        return self.__nums[key]
