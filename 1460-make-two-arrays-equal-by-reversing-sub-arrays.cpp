#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool canBeEqual(vector<int>& target, vector<int>& arr) {
		unordered_map<int, int> cnt1, cnt2;
		for (int i = 0; i < arr.size(); i++) {
			++cnt1[target[i]];
			++cnt2[arr[i]];
		}
		if (cnt1.size() != cnt2.size()) {
			return false;
		}
		for (auto &entry : cnt1) {
			if (!cnt2.count(entry.first) || cnt2[entry.first] != entry.second) {
				return false;
			}
		}
		return true;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.canBeEqual(vector<int> {1, 2, 3, 4}, vector<int> {2, 4, 1, 3}) << endl;
}
