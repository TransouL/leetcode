#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
	unordered_map<string, vector<int>> scope;

	string parseVar(const string &expression, int &start) {
		int n = expression.size();
		string ret;
		while (start < n && expression[start] != ' ' && expression[start] != ')') {
			ret.push_back(expression[start++]);
		}
		return ret;
	}

	int parseInt(const string &expression, int &start) {
		int n = expression.size();
		int ret = 0, sign = 1;
		if (expression[start] == '-') {
			sign = -1;
			++start;
		}
		while (start < n && isdigit(expression[start])) {
			ret = ret * 10 + (expression[start] - '0');
			++start;
		}
		return sign * ret;
	}

	int innerEvaluate(const string &expression, int &start) {
		if (expression[start] != '(') {
			if (islower(expression[start])) {
				string var = parseVar(expression, start);
				return scope[var].back();
			}
			else {
				return parseInt(expression, start);
			}
		}
		
		int ret;
		++start;
		if (expression[start] == 'l') {
			start += 4;
			vector<string> vars;
			while (true) {
				if (!islower(expression[start])) {
					ret = innerEvaluate(expression, start);
					break;
				}
				string var = parseVar(expression, start);
				if (expression[start] == ')') {
					ret = scope[var].back();
					break;
				}
				vars.push_back(var);
				start++;
				int e = innerEvaluate(expression, start);
				scope[var].push_back(e);
				start++;
			}
			// 针对在这个过程中更新过作用域的变量，清除当前作用域的值
			for (auto &var : vars) {
				scope[var].pop_back();
			}
		}
		else if (expression[start] == 'a') {
			start += 4;
			int e1 = innerEvaluate(expression, start);
			start++;
			int e2 = innerEvaluate(expression, start);
			ret = e1 + e2;
		}
		else {
			start += 5;
			int e1 = innerEvaluate(expression, start);
			start++;
			int e2 = innerEvaluate(expression, start);
			ret = e1 * e2;
		}
		start++;
		return ret;
	}

public:
	int evaluate(string expression) {
		int start = 0;
		return innerEvaluate(expression, start);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))") << endl;
	cout << solution.evaluate("(let x 3 x 2 x)") << endl;
	cout << solution.evaluate("(let x 1 y 2 x (add x y) (add x y))") << endl;
}
