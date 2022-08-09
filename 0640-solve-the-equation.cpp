#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string solveEquation(string equation) {
		int a = 0, b = 0, curr = -1;
		bool left = true, minus = false;
		for (auto &ch : equation) {
			switch (ch) {
			case '=':
				if (curr != -1) {
					if (minus) {
						b += curr;
					}
					else {
						b -= curr;
					}
				}
				left = false;
				curr = -1;
				minus = false;
				break;
			case 'x':
				if (curr == -1){
					curr = 1;
				}
				if (left ^ minus) {
					a += curr;
				}
				else {
					a -= curr;
				}
				curr = -1;
				break;
			case '-':
				if (curr != -1) {
					if (left ^ minus) {
						b -= curr;
					}
					else {
						b += curr;
					}
				}
				curr = -1;
				minus = true;
				break;
			case '+':
				if (curr != -1) {
					if (left ^ minus) {
						b -= curr;
					}
					else {
						b += curr;
					}
				}
				curr = -1;
				minus = false;
				break;
			default:
				if (curr == -1) {
					curr = ch - '0';
				}
				else {
					curr = curr * 10 + (ch - '0');
				}
				break;
			}
		}

		if (curr != -1) {
			if (minus) {
				b -= curr;
			}
			else {
				b += curr;
			}
		}

		if (a == 0) {
			if (b == 0) {
				return "Infinite solutions";
			}
			else {
				return "No solution";
			}
		}
		if (b % a == 0) {
			return "x=" + to_string(b/a);
		}
		return "No solution";
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.solveEquation("x+5-3+x=6+x-2") << endl;
	cout << solution.solveEquation("x=x") << endl;
	cout << solution.solveEquation("2x=x") << endl;
	cout << solution.solveEquation("2x+3x-6x=x+2") << endl; // "x=-1"
	cout << solution.solveEquation("2=-x") << endl; // "x=-2"
	cout << solution.solveEquation("0x=0") << endl; // "Infinite solutions"
}
