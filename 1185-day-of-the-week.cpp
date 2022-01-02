#include <iostream>
#include <string>

using namespace std;

const string week[] = { "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
const int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };

class Solution {
public:
	string dayOfTheWeek(int day, int month, int year) {
		int days = 365 * (year - 1971) + (year - 1969) / 4;
		for (int i = 0; i < month - 1; i++)
			days += monthDays[i];
		if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			days += 1;
		return week[(days + day) % 7];
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.dayOfTheWeek(31, 8, 2019) << endl;
	cout << solution.dayOfTheWeek(1, 1, 1971) << endl;
	cout << solution.dayOfTheWeek(31, 12, 2100) << endl;
}
