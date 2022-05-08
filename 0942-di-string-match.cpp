#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> diStringMatch(string s) {
		int n = s.length();
		int l = 0, r = n;
		vector<int> ans(n + 1);
		for (int i = 0; i < n; i++) {
			if (s[i] == 'I') {
				ans[i] = l++;
			}
			else {
				ans[i] = r--;
			}
		}
		ans[n] = l;
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
	printVector(solution.diStringMatch("IDID"));
	printVector(solution.diStringMatch("III"));
	printVector(solution.diStringMatch("DDI"));
}
