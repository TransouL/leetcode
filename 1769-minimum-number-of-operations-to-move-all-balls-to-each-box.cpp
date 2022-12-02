#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> minOperations(string boxes) {
		int left = boxes[0] - '0', right = 0, ops = 0, n = boxes.size();
		for (int i = 1; i < n; i++) {
			if (boxes[i] == '1') {
				++right;
				ops += i;
			}
		}
		vector<int> ans(n);
		ans[0] = ops;
		for (int i = 1; i < n; i++) {
			ops += left - right;
			ans[i] = ops;
			if (boxes[i] == '1') {
				++left;
				--right;
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

int main(void) {
	Solution solution = Solution();
	printVector(solution.minOperations("110"));
	printVector(solution.minOperations("001011"));
}