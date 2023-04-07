#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> numMovesStonesII(vector<int>& s) {
		sort(s.begin(), s.end());
		int n = s.size();
		int e1 = s[n - 2] - s[0] - n + 2;
		int e2 = s[n - 1] - s[1] - n + 2;
		int max_move = max(e1, e2);
		if (e1 == 0 || e2 == 0) {
			return{ min(2, max_move), max_move };
		}
		int max_cnt = 0, left = 0;
		for (int right = 0; right < n; ++right) {
			while (s[right] - s[left] + 1 > n) {
				++left;
			}
			max_cnt = max(max_cnt, right - left + 1);
		}
		return{ n - max_cnt, max_move };
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &&e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.numMovesStonesII(vector<int>{7, 4, 9}));
	printVector(solution.numMovesStonesII(vector<int>{6, 5, 4, 3, 10}));
	printVector(solution.numMovesStonesII(vector<int>{100, 101, 104, 102, 103}));
}