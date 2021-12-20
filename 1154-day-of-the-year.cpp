#include <iostream>
#include <string>

using namespace std;
const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Solution {
public:
	int dayOfYear(string date) {
		int year = stoi(date.substr(0, 4));
		int month = stoi(date.substr(5, 2));
		int ans = stoi(date.substr(8, 2));
		for (int i = 0; i < month - 1; i++)
			ans += days[i];
		if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month > 2)
			++ans;
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.dayOfYear("2019-01-09") << endl;
	cout << solution.dayOfYear("2019-02-10") << endl;
	cout << solution.dayOfYear("2003-03-01") << endl;
	cout << solution.dayOfYear("2004-03-01") << endl;
}
