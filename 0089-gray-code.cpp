#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ans;
		ans.emplace_back(0);
		for (int i = 0; i < n; i++) {
			int currSize = ans.size();
			for (int j = currSize - 1; j >= 0; --j) {
				ans.emplace_back(ans[j] | (1 << i));
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
	for (int i = 1; i <= 12; i++) {
		printVector(solution.grayCode(i));
	}
}
