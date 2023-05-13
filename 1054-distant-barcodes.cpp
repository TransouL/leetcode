#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		int n = barcodes.size();
		if (n < 3) {
			return barcodes;
		}

		unordered_map<int, int> stats;
		for (auto &b : barcodes) {
			++stats[b];
		}

		vector<int> ans(n);
		int evenIdx = 0, oddIdx = 1, half = n / 2;
		for (auto &p : stats){
			int x = p.first, cx = p.second;
			if (cx <= half) {
				for (; cx > 0 && oddIdx < n; --cx, oddIdx += 2) {
					ans[oddIdx] = x;
				}
			}
			for (; cx > 0; --cx, evenIdx += 2) {
				ans[evenIdx] = x;
			}
		}

		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &&e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.rearrangeBarcodes(vector<int>{1, 1, 1, 2, 2, 2}));
	printVector(solution.rearrangeBarcodes(vector<int>{1, 1, 1, 1, 2, 2, 3, 3}));
	printVector(solution.rearrangeBarcodes(vector<int>{1}));
	printVector(solution.rearrangeBarcodes(vector<int>{1, 1, 2}));
	printVector(solution.rearrangeBarcodes(vector<int>{1, 1, 2, 2, 3, 3, 4, 4, 5, 5}));
}