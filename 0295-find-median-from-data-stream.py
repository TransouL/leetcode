import heapq


class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.left_max_heap = []
        self.right_min_heap = []

    def addNum(self, num: int) -> None:
        left_count, right_count = len(self.left_max_heap), len(self.right_min_heap)
        if not self.left_max_heap or num <= -self.left_max_heap[0]:
            heapq.heappush(self.left_max_heap, -num)
            if left_count > right_count:
                heapq.heappush(self.right_min_heap, -heapq.heappop(self.left_max_heap))
        else:
            heapq.heappush(self.right_min_heap, num)
            if left_count < right_count:
                heapq.heappush(self.left_max_heap, -heapq.heappop(self.right_min_heap))

    def findMedian(self) -> float:
        left_count, right_count = len(self.left_max_heap), len(self.right_min_heap)
        if left_count > right_count:
            return -self.left_max_heap[0]
        elif left_count == right_count:
            return (-self.left_max_heap[0] + self.right_min_heap[0]) / 2
        else:
            return self.right_min_heap[0]


# Your MedianFinder object will be instantiated and called as such:
obj = MedianFinder()
obj.addNum(1)
obj.addNum(2)
print(obj.findMedian())
obj.addNum(3)
print(obj.findMedian())
obj.addNum(4)
print(obj.findMedian())
