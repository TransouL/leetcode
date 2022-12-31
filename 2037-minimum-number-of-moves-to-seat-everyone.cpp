#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minMovesToSeat(vector<int>& seats, vector<int>& students) {
		sort(seats.begin(), seats.end());
		sort(students.begin(), students.end());
		int ans = 0;
		for (int i = 0; i < seats.size(); i++) {
			ans += abs(seats[i] - students[i]);
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minMovesToSeat(vector<int>{3, 1, 5}, vector<int>{2, 7, 4}) << endl;
	cout << solution.minMovesToSeat(vector<int>{12, 14, 19, 19, 12}, vector<int>{19, 2, 17, 20, 7}) << endl; // 19
}