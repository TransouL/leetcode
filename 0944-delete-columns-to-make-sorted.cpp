#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minDeletionSize(vector<string>& strs) {
		int m = strs[0].size(), ans = 0;
		vector<bool> flag(m, true);
		vector<char> curr(m, 'a');
		for (auto &str : strs) {
			for (int i = 0; i < m; i++) {
				if (flag[i] && curr[i] > str[i]) {
					++ans;
					flag[i] = false;
				}
				else {
					curr[i] = str[i];
				}
			}
			if (ans == m) {
				break;
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.minDeletionSize(vector<string> {"cba", "daf", "ghi"}) << endl;
	cout << solution.minDeletionSize(vector<string> {"a", "b"}) << endl;
	cout << solution.minDeletionSize(vector<string> {"zyx", "wvu", "tsr"}) << endl;
}
