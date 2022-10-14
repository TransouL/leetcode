#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> buildArray(vector<int>& target, int n) {
		vector<string> ans;
		target.insert(target.begin(), 0);
		for (int i = 1; i < target.size(); i++) {
			int cnt = target[i] - target[i - 1];
			if (cnt == 1) {
				ans.emplace_back("Push");
			}
			else {
				while (cnt-- > 1) {
					ans.emplace_back("Push");
					ans.emplace_back("Pop");
				}
				ans.emplace_back("Push");
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
	printVector(solution.buildArray(vector<int> {1, 3}, 3));
	printVector(solution.buildArray(vector<int> {1, 2, 3}, 3));
	printVector(solution.buildArray(vector<int> {1, 2}, 4));
}
