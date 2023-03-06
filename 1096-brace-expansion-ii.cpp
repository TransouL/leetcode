#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
	vector<string> braceExpansionII(string expression) {
		vector<char> op;
		vector<set<string>> stk;

		auto ope = [&]() {
			int l = stk.size() - 2, r = stk.size() - 1;
			if (op.back() == '+') {
				stk[l].insert(stk[r].begin(), stk[r].end());
			}
			else {
				set<string> tmp;
				for (auto &left : stk[l]) {
					for (auto &right : stk[r]) {
						tmp.insert(left + right);
					}
				}
				stk[l] = move(tmp);
			}
			op.pop_back();
			stk.pop_back();
		};

		for (int i = 0; i < expression.size(); i++) {
			if (expression[i] == ',') {
				while (op.size() && op.back() == '*') {
					ope();
				}
				op.push_back('+');
			}
			else if (expression[i] == '{') {
				if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1]))) {
					op.push_back('*');
				}
				op.push_back('{');
			}
			else if (expression[i] == '}') {
				while (op.size() && op.back() != '{') {
					ope();
				}
				op.pop_back();
			}
			else {
				if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1]))) {
					op.push_back('*');
				}
				stk.push_back({ string(1, expression[i]) });
			}
		}

		while (op.size()) {
			ope();
		}
		return {stk.back().begin(), stk.back().end()};
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.braceExpansionII("{a,b}{c,{d,e}}"));
	printVector(solution.braceExpansionII("{{a,z},a{b,c},{ab,z}}"));
}