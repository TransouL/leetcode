#include <iostream>
#include <map>
using namespace std;

class MyCalendar {
	map<int, int> intervals;

public:
	MyCalendar() {}

	bool book(int start, int end) {
		if (intervals.empty()) {
			intervals[start] = end;
			return true;
		}

		auto it = intervals.lower_bound(end);
		if (it == intervals.begin()) {
			if (it->first == end) {
				int right = it->second;
				intervals.erase(it);
				intervals[start] = right;
			}
			else {
				intervals[start] = end;
			}
			return true;
		}

		--it;
		if (it->second < start) {
			intervals[start] = end;
			return true;
		}
		else if (it->second == start) {
			intervals[it->first] = end;
			return true;
		}
		return false;
	}
};

int main(void){
	MyCalendar myCalendar = MyCalendar();
	cout << myCalendar.book(10, 20) << endl; // return True
	cout << myCalendar.book(15, 25) << endl; // return False
	cout << myCalendar.book(20, 30) << endl; // return True 
}