#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
		int m = rolls.size(), total = mean * (m + n);
		for (auto &roll : rolls) {
			total -= roll;
		}
		vector<int> ans;
		if (total >= n && total <= n * 6) {
			ans.reserve(n);
			int value = total / n, left = total - value * n;
			for (int i = 0; i < left; i++) {
				ans.emplace_back(value + 1);
			}
			for (int i = left; i < n; i++) {
				ans.emplace_back(value);
			}
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.missingRolls(vector<int> {3, 2, 4, 3}, 4, 2));
	printVector(solution.missingRolls(vector<int> {1, 5, 6}, 3, 4));
	printVector(solution.missingRolls(vector<int> {1, 2, 3, 4}, 6, 4));
	printVector(solution.missingRolls(vector<int> {1}, 3, 1));
	printVector(solution.missingRolls(vector<int> {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 1, 1));
}
