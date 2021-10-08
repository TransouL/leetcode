from typing import List
from sortedcontainers import SortedDict


class SummaryRanges:

    def __init__(self):
        self.intervals = SortedDict()

    def addNum(self, val: int) -> None:
        itvs = self.intervals
        keys_ = self.intervals.keys()
        values_ = self.intervals.values()

        itv1idx = itvs.bisect_right(val)
        itv0idx = len(itvs) if itv1idx == 0 else itv1idx - 1

        if itv0idx != len(itvs) and keys_[itv0idx] <= val <= values_[itv0idx]:
            return
        left_aside = itv0idx != len(itvs) and values_[itv0idx] + 1 == val
        right_aside = itv1idx != len(itvs) and keys_[itv1idx] - 1 == val
        if left_aside and right_aside:
            left, right = keys_[itv0idx], values_[itv1idx]
            itvs.popitem(itv1idx)
            itvs.popitem(itv0idx)
            itvs[left] = right
        elif left_aside:
            itvs[keys_[itv0idx]] = val
        elif right_aside:
            right = values_[itv1idx]
            itvs.popitem(itv1idx)
            itvs[val] = right
        else:
            itvs[val] = val

    def getIntervals(self) -> List[List[int]]:
        return list(self.intervals.items())


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(val)
# param_2 = obj.getIntervals()
summaryRanges = SummaryRanges()
summaryRanges.addNum(1)  # arr = [1]
print(summaryRanges.getIntervals())  # 返回 [[1, 1]]
summaryRanges.addNum(3)  # arr = [1, 3]
print(summaryRanges.getIntervals())  # 返回 [[1, 1], [3, 3]]
summaryRanges.addNum(7)  # arr = [1, 3, 7]
print(summaryRanges.getIntervals())  # 返回 [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2)  # arr = [1, 2, 3, 7]
print(summaryRanges.getIntervals())  # 返回 [[1, 3], [7, 7]]
summaryRanges.addNum(6)  # arr = [1, 2, 3, 6, 7]
print(summaryRanges.getIntervals())  # 返回 [[1, 3], [6, 7]]
