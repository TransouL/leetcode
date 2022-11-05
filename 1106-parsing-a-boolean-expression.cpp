#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	bool parseBoolExpr(string expression) {
		stack<char> stk;
		int n = expression.size();
		for (auto &c : expression) {
			if (c == ',') {
				continue;
			}
			else if (c != ')') {
				stk.push(c);
			}
			else {
				bool t = 0, f = 0;
				while (stk.top() != '(') {
					char val = stk.top();
					stk.pop();
					if (val == 't') {
						t = true;
					}
					else {
						f = true;
					}
				}
				stk.pop(); // '('
				char op = stk.top();
				stk.pop();
				switch (op) {
				case '!':
					stk.push(f ? 't' : 'f');
					break;
				case '&':
					stk.push(f ? 'f' : 't');
					break;
				case '|':
					stk.push(t ? 't' : 'f');
					break;
				default:
					break;
				}
			}
		}
		return stk.top() == 't';
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.parseBoolExpr("!(f)") << endl;
	cout << solution.parseBoolExpr("|(f,t)") << endl;
	cout << solution.parseBoolExpr("&(t,f)") << endl;
	cout << solution.parseBoolExpr("|(&(t,f,t),!(t))") << endl;
}
