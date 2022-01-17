#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define min(a,b) ((a) < (b) ? (a) : (b))

class Solution {
	int getMinutes(string &t) {
		return (int(t[0] - '0') * 10 + int(t[1] - '0')) * 60 + int(t[3] - '0') * 10 + int(t[4] - '0');
	}

public:
	int findMinDifference(vector<string>& timePoints) {
		int n = timePoints.size();
		if (n > 1440) {
			return 0;
		}
		sort(timePoints.begin(), timePoints.end());
		int mins0 = getMinutes(timePoints[0]);
		int ans = mins0 + 1440 - getMinutes(timePoints[n - 1]);
		int pre = mins0;
		for (int i = 1; i < n; i++) {
			int mins = getMinutes(timePoints[i]);
			ans = min(ans, mins - pre);
			if (ans == 0) {
				return 0;
			}
			pre = mins;
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.findMinDifference(vector<string> {"23:59", "00:00"}) << endl;
	cout << solution.findMinDifference(vector<string> {"00:00", "23:59", "00:00"}) << endl;
}
