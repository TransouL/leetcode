#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> decrypt(vector<int>& code, int k) {
		int n = code.size();
		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			int tmp = 0;
			if (k > 0) {
				for (int j = 1; j <= k; j++) {
					tmp += (code[(i + j) % n]);
				}
			}
			else if (k < 0) {
				for (int j = -1; j >= k; j--) {
					int idx = i + j;
					if (idx < 0) {
						idx += n;
					}
					tmp += (code[idx]);
				}
			}
			ans[i] = tmp;
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
	printVector(solution.decrypt(vector<int> {5, 7, 1, 4}, 3));
	printVector(solution.decrypt(vector<int> {1, 2, 3, 4}, 0));
	printVector(solution.decrypt(vector<int> {2, 4, 9, 3}, -2));
}