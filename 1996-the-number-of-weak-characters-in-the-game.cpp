#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
	int numberOfWeakCharacters(vector<vector<int>>& properties) {
		int n = properties.size();
		sort(properties.begin(), properties.end());

		map<int, int, greater<int>> maxMapping;
		maxMapping.emplace(properties.back()[1], properties.back()[0]);
		int ans = 0;
		for (int i = n - 2; i >= 0; --i) {
			int attacki = properties[i][0], defensei = properties[i][1];
			if (maxMapping.count(defensei)) {
				if (maxMapping[defensei] <= attacki) {
					maxMapping[defensei] = attacki;
					continue;
				}
			}

			for (auto iter = maxMapping.begin(); iter != maxMapping.end(); ++iter) {
				int k = iter->first, v = iter->second;
				if (k > defensei) {
					if (v > attacki) {
						++ans;
						break;
					}
				}
				else {
					maxMapping.emplace(defensei, attacki);
					break;
				}
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.numberOfWeakCharacters(vector<vector<int>> { { 5, 5 }, { 6, 3 }, { 3, 6 } }) << endl;
	cout << solution.numberOfWeakCharacters(vector<vector<int>> { { 2, 2 }, { 3, 3 } }) << endl;
	cout << solution.numberOfWeakCharacters(vector<vector<int>> { { 1, 5 }, { 10, 4 }, { 4, 3 } }) << endl;
	cout << solution.numberOfWeakCharacters(vector<vector<int>> { { 1, 5 }, { 10, 4 }, { 4, 3 }, { 11, 2 } }) << endl;
}
