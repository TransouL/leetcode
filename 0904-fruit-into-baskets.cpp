#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int totalFruit(vector<int>& fruits) {
		int ans = 0, start1 = 0, v1 = fruits[0], end1 = 0, start2, v2 = -1, end2, n = fruits.size();
		for (int i = 1; i < n; i++) {
			int v = fruits[i];
			if (v == v1) {
				end1 = i;
			}
			else if (v2 == -1) {
				v2 = v;
				start2 = i;
				end2 = i;
			}
			else if (v == v2) {
				end2 = i;
			}
			else {
				ans = max(ans, i - start1);
				if (fruits[i - 1] == v1) {
					start1 = end2 + 1;
				}
				else {
					start1 = end1 + 1;
					end1 = end2;
					v1 = v2;
				}
				start2 = i;
				end2 = i;
				v2 = v;
			}
		}
		return max(ans, n - start1);
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.totalFruit(vector<int> {1, 2, 1}) << endl;
	cout << solution.totalFruit(vector<int> {0, 1, 2, 2}) << endl;
	cout << solution.totalFruit(vector<int> {1, 2, 3, 2, 2}) << endl;
	cout << solution.totalFruit(vector<int> {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4}) << endl;
}
