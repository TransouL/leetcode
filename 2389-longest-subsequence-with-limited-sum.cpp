#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
		int n = nums.size(), m = queries.size();
		sort(nums.begin(), nums.end());
		vector<int> f(n + 1);
		for (int i = 0; i < n; i++) {
			f[i + 1] = f[i] + nums[i];
		}
		vector<int> ans(m);
		for (int i = 0; i < m; i++) {
			ans[i] = upper_bound(f.begin(), f.end(), queries[i]) - f.begin() - 1;
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.answerQueries(vector<int>{4, 5, 2, 1}, vector<int>{3, 10, 21}));
	printVector(solution.answerQueries(vector<int>{2, 3, 4, 5}, vector<int>{1}));
}