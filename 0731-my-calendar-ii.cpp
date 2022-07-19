#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

class MyCalendarTwo {
private:
	vector<pii> booked;
	vector<pii> overlaps;
public:
	MyCalendarTwo() {}

	bool book(int start, int end) {
		for (auto &overlap : overlaps) {
			auto l = overlap.first, r = overlap.second;
			if (l < end && start < r) {
				return false;
			}
		}

		for (auto &record : booked) {
			auto l = record.first, r = record.second;
			if (l < end && start < r) {
				overlaps.emplace_back(max(l, start), min(r, end));
			}
		}
		booked.emplace_back(start, end);
		return true;
	}
};

int main(void){
	MyCalendarTwo myCalendar = MyCalendarTwo();
	cout << myCalendar.book(10, 20) << endl; // returns true
	cout << myCalendar.book(50, 60) << endl; // returns true
	cout << myCalendar.book(10, 40) << endl; // returns true
	cout << myCalendar.book(5, 15) << endl; // returns false
	cout << myCalendar.book(5, 10) << endl; // returns true
	cout << myCalendar.book(25, 55) << endl; // returns true
}
