#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<bool> camelMatch(vector<string>& queries, string pattern) {
		int n = queries.size();
		vector<bool> ans(n, true);
		for (int i = 0; i < n; i++) {
			int p = 0;
			for (auto &q : queries[i]) {
				if (p < pattern.length() && q == pattern[p]) {
					++p;
				}
				else if (isupper(q)) {
					ans[i] = false;
					break;
				}
			}
			if (p < pattern.length()) {
				ans[i] = false;
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
	printVector(solution.camelMatch(vector<string>{"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"}, "FB"));
	printVector(solution.camelMatch(vector<string>{"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"}, "FoBa"));
	printVector(solution.camelMatch(vector<string>{"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"}, "FoBaT"));
}