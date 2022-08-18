#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		int n = startTime.size(), ans = 0;
		for (int i = 0; i < n; i++) {
			if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
				++ans;
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.busyStudent(vector<int> {1, 2, 3}, vector<int> {3, 2, 7}, 4) << endl;
	cout << solution.busyStudent(vector<int> {4}, vector<int> {4}, 4) << endl;
	cout << solution.busyStudent(vector<int> {4}, vector<int> {4}, 5) << endl;
}
