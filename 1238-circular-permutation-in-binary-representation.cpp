#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> circularPermutation(int n, int start) {
		vector<int> ans(1 << n);
		for (int i = 0; i < ans.size(); i++) {
			ans[i] = (i >> 1) ^ i ^ start;
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
	printVector(solution.circularPermutation(2, 3));
	printVector(solution.circularPermutation(3, 2));
}