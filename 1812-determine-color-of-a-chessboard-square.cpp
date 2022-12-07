#include <iostream>
using namespace std;

class Solution {
public:
	bool squareIsWhite(string coordinates) {
		return ((coordinates[0] - 'a') ^ (coordinates[1] - '1')) & 1;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.squareIsWhite("a1") << endl;
	cout << solution.squareIsWhite("h3") << endl;
	cout << solution.squareIsWhite("c7") << endl;
}