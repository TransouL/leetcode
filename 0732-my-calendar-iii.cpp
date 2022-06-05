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
	cout << myCalendarThree.book(10, 20) << endl; // ���� 1 ����һ���ճ̰��ſ���Ԥ�����Ҳ������ཻ��������� k ��Ԥ���� 1 ��Ԥ����
	cout << myCalendarThree.book(50, 60) << endl; // ���� 1 ���ڶ����ճ̰��ſ���Ԥ�����Ҳ������ཻ��������� k ��Ԥ���� 1 ��Ԥ����
	cout << myCalendarThree.book(10, 40) << endl; // ���� 2 ���������ճ̰��� [10, 40) ���һ���ճ̰����ཻ��������� k ��Ԥ���� 2 ��Ԥ����
	cout << myCalendarThree.book(5, 15) << endl; // ���� 3 ��ʣ�µ��ճ̰��ŵ���� k ��Ԥ���� 3 ��Ԥ����
	cout << myCalendarThree.book(5, 10) << endl; // ���� 3
	cout << myCalendarThree.book(25, 55) << endl; // ���� 3
}
