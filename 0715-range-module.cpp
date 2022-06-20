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
	cout << rangeModule.queryRange(10, 14) << endl;  // ���� true ������[10, 14) �е�ÿ���������ڱ����٣�
	cout << rangeModule.queryRange(13, 15) << endl; // ���� false��δ��������[13, 15) ���� 14, 14.03, 14.17 ���������֣�
	cout << rangeModule.queryRange(16, 17) << endl; //���� true ������ִ����ɾ������������[16, 17) �е����� 16 ��Ȼ�ᱻ���٣�
}
