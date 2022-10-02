#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool canTransform(string start, string end) {
		int n1 = start.size(), n2 = end.size();
		if (n1 != n2) {
			return false;
		}
		int i = 0, j = 0;
		while (i < n1 && j < n1) {
			while (i < n1 && start[i] == 'X') {
				++i;
			}
			while (j < n1 && end[j] == 'X') {
				++j;
			}
			if (i < n1 && j < n1) {
				if ((start[i] != end[j]) || (start[i] == 'L' && i <j) || (start[i] == 'R' && i >j)) {
					return false;
				}
				++i;
				++j;
			}
		}
		while (i < n1 && start[i] == 'X') {
			++i;
		}
		while (j < n1 && end[j] == 'X') {
			++j;
		}
		return i == n1 && j == n1;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.canTransform("RXXLRXRXL", "XRLXXRRLX") << endl;
	cout << solution.canTransform("LXXLXRLXXL", "XLLXRXLXLX") << endl; // false
	cout << solution.canTransform("XLLR", "LXLX") << endl; // false
}
