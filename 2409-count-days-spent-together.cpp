#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
	int calcDayOfYear(string day, const int pre[12]) {
		int month = stoi(day.substr(0, 2));
		int date = stoi(day.substr(3));
		return pre[month - 1] + date;
	}

public:
	int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
		int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int pre[13] = {0};
		for (int i = 1; i < 13; i++) {
			pre[i] = pre[i - 1] + days[i - 1];
		}

		int aa = calcDayOfYear(arriveAlice, pre);
		int al = calcDayOfYear(leaveAlice, pre);
		int ba = calcDayOfYear(arriveBob, pre);
		int bl = calcDayOfYear(leaveBob, pre);
		return max(0, min(al, bl) - max(aa, ba) + 1);
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.countDaysTogether("08-15", "08-18", "08-16", "08-19") << endl;
	cout << solution.countDaysTogether("10-01", "10-31", "11-01", "12-31") << endl;
}