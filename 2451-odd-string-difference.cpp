#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
	vector<int> diff(string str) {
		vector<int> res(str.length() - 1);
		for (int i = 0; i < str.length() - 1; i++) {
			res[i] = str[i + 1] - str[i];
		}
		return res;
	}

	bool check(vector<int> diff1, vector<int> diff2){
		for (int i = 0; i < diff1.size(); i++) {
			if (diff1[i] != diff2[i]) {
				return false;
			}
		}
		return true;
	}

public:
	string oddString(vector<string>& words) {
		int n = words.size();
		vector<int> first = diff(words[0]), second;
		bool isFirstSame = false, isSecondFound = false;
		int secondIdx = -1;
		for (int i = 1; i < n; i++) {
			vector<int> diffTmp = diff(words[i]);
			if (isFirstSame) {
				if (!check(first, diffTmp)) {
					return words[i];
				}
			}
			else {
				if (isSecondFound) {
					if (check(first, diffTmp)) {
						return words[secondIdx];
					}
					else {
						return words[0];
					}
				}
				else {
					if (check(first, diffTmp)) {
						isFirstSame = true;
					}
					else {
						isSecondFound = true;
						secondIdx = i;
						second = diffTmp;
					}
				}
			}
		}
		return nullptr;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.oddString(vector<string> {"adc", "wzy", "abc"}) << endl;
	cout << solution.oddString(vector<string> {"aaa", "bob", "ccc", "ddd"}) << endl;
}