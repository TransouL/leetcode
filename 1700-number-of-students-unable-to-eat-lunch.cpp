#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int countStudents(vector<int>& students, vector<int>& sandwiches) {
		int cnt0 = 0, cnt1 = 0;
		for (auto &s : students) {
			if (s == 0) {
				++cnt0;
			}
			else {
				++cnt1;
			}
		}
		for (auto &s : sandwiches) {
			if (s == 0) {
				--cnt0;
				if (cnt0 < 0) {
					return cnt1;
				}
			}
			else {
				--cnt1;
				if (cnt1 < 0) {
					return cnt0;
				}
			}
		}
		return 0;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.countStudents(vector<int> {1, 1, 0, 0}, vector<int> {0, 1, 0, 1}) << endl;
	cout << solution.countStudents(vector<int> {1, 1, 1, 0, 0, 1}, vector<int> {1, 0, 0, 0, 1, 1}) << endl;
}
