#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
		int n = s.length();

		vector<int> left(n);
		vector<int> pre(n + 1, 0);
		for (int i = 0, sum_ = 0, l = -1; i < n; i++) {
			if (s[i] == '*') {
				++sum_;
			}
			else {
				l = i;
			}
			pre[i] = sum_;
			left[i] = l;
		}

		vector<int> right(n);
		for (int i = n - 1, r = -1; i >= 0; --i) {
			if (s[i] == '|') {
				r = i;
			}
			right[i] = r;
		}

		vector<int> ans;
		for (auto &q : queries) {
			int l = right[q[0]], r = left[q[1]];
			ans.emplace_back(l == -1 || r == -1 || l >= r ? 0 : pre[r] - pre[l]);
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
	printVector(solution.platesBetweenCandles("**|**|***|", vector<vector<int>> {{2, 5}, { 5, 9 }}));
	printVector(solution.platesBetweenCandles("***|**|*****|**||**|*", vector<vector<int>> {{1, 17}, { 4, 5 }, { 14, 17 }, { 5, 11 }, { 15, 16 }}));
}
