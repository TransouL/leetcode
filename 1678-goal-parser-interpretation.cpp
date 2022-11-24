﻿#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string interpret(string command) {
		string ans;
		for (int i = 0; i < command.size(); i++) {
			if (command[i] == 'G') {
				ans += 'G';
			}
			else if (command[i] == '(') {
				if (command[i + 1] == ')') {
					ans += 'o';
					++i;
				}
				else {
					ans += "al";
					i += 3;
				}
			}
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.interpret("G()(al)") << endl;
	cout << solution.interpret("G()()()()(al)") << endl;
	cout << solution.interpret("(al)G(al)()()G") << endl;
}