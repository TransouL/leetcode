#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class RangeModule {
	map<int, int> intervals;
	
public:
	RangeModule() {}

	void addRange(int left, int right) {
		auto it = intervals.upper_bound(left);
		if (it != intervals.begin()) {
			auto start = prev(it);
			if (start->second >= right) {
				return;
			}
			if (start->second >= left) {
				left = start->first;
				intervals.erase(start);
			}
		}
		while (it != intervals.end() && it->first <= right) {
			right = max(right, it->second);
			it = intervals.erase(it);
		}
		intervals[left] = right;
	}

	bool queryRange(int left, int right) {
		auto it = intervals.upper_bound(left);
		if (it == intervals.begin()) {
			return false;
		}
		it = prev(it);
		return right <= it->second;
	}

	void removeRange(int left, int right) {
		auto it = intervals.upper_bound(left);
		if (it != intervals.begin()) {
			auto start = prev(it);
			if (start->second >= right) {
				int ri = start->second;
				if (start->first == left) {
					intervals.erase(start);
				}
				else {
					start->second = left;
				}
				if (right != ri) {
					intervals[right] = ri;
				}
				return;
			}
			else if (start->second > left) {
				start->second = left;
			}
		}
		while (it != intervals.end() && it->first < right) {
			if (it->second <= right) {
				it = intervals.erase(it);
			}
			else {
				intervals[right] = it->second;
				intervals.erase(it);
				break;
			}
		}
	}
};

int main(void){
	RangeModule rangeModule = RangeModule();
	rangeModule.addRange(10, 20);
	rangeModule.removeRange(14, 16);
	cout << rangeModule.queryRange(10, 14) << endl;  // 返回 true （区间[10, 14) 中的每个数都正在被跟踪）
	cout << rangeModule.queryRange(13, 15) << endl; // 返回 false（未跟踪区间[13, 15) 中像 14, 14.03, 14.17 这样的数字）
	cout << rangeModule.queryRange(16, 17) << endl; //返回 true （尽管执行了删除操作，区间[16, 17) 中的数字 16 仍然会被跟踪）
}
