#include <iostream>
using namespace std;

class Solution {
public:
	int countVowelStrings(int n) {
		int a = 1, e = 1, i = 1, o = 1, u = 1;
		for (int j = 0; j < n; j++) {
			o += u;
			i += o;
			e += i;
			a += e;
		}
		return a;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.countVowelStrings(1) << endl;
	cout << solution.countVowelStrings(2) << endl;
	cout << solution.countVowelStrings(3) << endl;
	cout << solution.countVowelStrings(33) << endl;
	cout << solution.countVowelStrings(50) << endl;
}