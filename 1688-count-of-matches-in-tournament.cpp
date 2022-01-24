#include <iostream>

using namespace std;

class Solution {
public:
	int numberOfMatches(int n) {
		return n - 1;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.numberOfMatches(7) << endl;
	cout << solution.numberOfMatches(14) << endl;
}
