#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	int scoreOfParentheses(string s) {
		stack<int> st;
		for (auto &ch : s) {
			if (ch == '(') {
				st.emplace(-1);
			}
			else {
				int part = 0;
				while (true) {
					int tmp = st.top();
					st.pop();
					if (tmp == -1) {
						part = part == 0 ? 1 : part * 2;
						break;
					}
					else {
						part += tmp;
					}
				}
				st.emplace(part);
			}
		}
		int ans = 0;
		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.scoreOfParentheses("()") << endl;
	cout << solution.scoreOfParentheses("(())") << endl;
	cout << solution.scoreOfParentheses("()()") << endl;
	cout << solution.scoreOfParentheses("(()(()))") << endl;
}
