#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class MyCalendarThree {
	map<int, int> cnt;

public:
	MyCalendarThree() {}

	int book(int start, int end) {
		++cnt[start];
		--cnt[end];
		int ans = 0, maxBook = 0;
		for (auto &pair : cnt) {
			maxBook += pair.second;
			ans = max(maxBook, ans);
		}
		return ans;
	}
};

int main(void){
	MyCalendarThree myCalendarThree = MyCalendarThree();
	cout << myCalendarThree.book(10, 20) << endl; // 返回 1 ，第一个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
	cout << myCalendarThree.book(50, 60) << endl; // 返回 1 ，第二个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
	cout << myCalendarThree.book(10, 40) << endl; // 返回 2 ，第三个日程安排 [10, 40) 与第一个日程安排相交，所以最大 k 次预订是 2 次预订。
	cout << myCalendarThree.book(5, 15) << endl; // 返回 3 ，剩下的日程安排的最大 k 次预订是 3 次预订。
	cout << myCalendarThree.book(5, 10) << endl; // 返回 3
	cout << myCalendarThree.book(25, 55) << endl; // 返回 3
}
