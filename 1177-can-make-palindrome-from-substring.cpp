#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
		int n = queries.size(), m = s.length();
		vector<int> pre(m + 1);
		for (int i = 0; i < m; i++) {
			pre[i + 1] = pre[i] ^ (1 << (s[i] - 'a'));
		}

		vector<bool> ans(n, false);
		for (int q = 0; q < n; q++) {
			int left = queries[q][0], right = queries[q][1], k = queries[q][2];
			int x = pre[left] ^ pre[right + 1];
			int ones = 0;
			while (x > 0) {
				++ones;
				x &= x - 1;
			}
			if (k >= ones / 2) {
				ans[q] = true;
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
	printVector(solution.canMakePaliQueries("abcda", vector<vector<int>>{{3, 3, 0}, { 1, 2, 0 }, { 0, 3, 1 }, { 0, 3, 2 }, { 0, 4, 1 }}));
}