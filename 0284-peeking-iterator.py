# Below is the interface for Iterator, which is already defined for you.
from builtins import StopIteration


class Iterator:
    def __init__(self, nums):
        """
        Initializes an iterator object to the beginning of a list.
        :type nums: List[int]
        """
        self.data = nums
        self.length = len(nums)
        self.curr = 0

    def hasNext(self):
        """
        Returns true if the iteration has more elements.
        :rtype: bool
        """
        return self.curr < self.length

    def next(self):
        """
        Returns the next element in the iteration.
        :rtype: int
        """
        if self.hasNext():
            ret = self.data[self.curr]
            self.curr += 1
            return ret
        else:
            raise StopIteration


class PeekingIterator:
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.iterator = iterator
        self._hasPeeked = False
        self._peekedE = None

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        if not self._hasPeeked:
            if self.hasNext():
                self._peekedE = self.iterator.next()
            self._hasPeeked = True
        return self._peekedE

    def next(self):
        """
        :rtype: int
        """
        if self._hasPeeked:
            ret = self._peekedE
            if self._peekedE is not None:
                self._peekedE = None
                self._hasPeeked = False
            return ret
        return self.iterator.next() if self.hasNext() else None

    def hasNext(self):
        """
        :rtype: bool
        """
        if self._hasPeeked:
            return self._peekedE is not None
        return self.iterator.hasNext()


# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].
it = PeekingIterator(Iterator([1, 2, 3]))
print(it.next())
print(it.peek())
print(it.next())
print(it.next())
print(it.hasNext())
print(it.peek())
print(it.next())
