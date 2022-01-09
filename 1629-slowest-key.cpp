#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	char slowestKey(vector<int>& releaseTimes, string keysPressed) {
		int n = releaseTimes.size();
		char ans = keysPressed[0];
		int currMax = releaseTimes[0];
		for (int i = 1; i < n; i++) {
			int dura = releaseTimes[i] - releaseTimes[i - 1];
			if (dura > currMax || (dura == currMax && keysPressed[i] > ans)) {
				currMax = dura;
				ans = keysPressed[i];
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.slowestKey(vector<int> {9, 29, 49, 50}, "cbcd") << endl;
	cout << solution.slowestKey(vector<int> {12, 23, 36, 46, 62}, "spuda") << endl;
}
