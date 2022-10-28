#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
		int keyId = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;
		int ans = 0;
		for (auto item : items) {
			if (ruleValue == item[keyId]) {
				++ans;
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.countMatches(vector<vector<string>>{ {"phone", "blue", "pixel"}, { "computer", "silver", "phone" }, { "phone", "gold", "iphone" }}, "type", "phone") << endl;
}

