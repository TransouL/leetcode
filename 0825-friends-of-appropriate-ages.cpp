#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numFriendRequests(vector<int>& ages) {
		vector<int> cnt(121);
		for (auto &age : ages)
			++cnt[age];
		vector<int> pre(121);
		for (size_t i = 1; i < 121; ++i)
			pre[i] = pre[i - 1] + cnt[i];
		int ans = 0;
		for (size_t i = 15; i < 121; ++i) {
			if (cnt[i]) {
				int bound = i / 2 + 7;
				ans += cnt[i] * (pre[i] - pre[bound] - 1);
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.numFriendRequests(vector<int> { 16, 16 }) << endl;
	cout << solution.numFriendRequests(vector<int> { 16, 17, 18 }) << endl;
	cout << solution.numFriendRequests(vector<int> { 20, 30, 100, 110, 120 }) << endl;
}
