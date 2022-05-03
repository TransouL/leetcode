#include <iostream>
using namespace std;

class Solution {
public:
	int findTheWinner(int n, int k) {
		return n == 1 ? 1 : (k + findTheWinner(n - 1, k) - 1) % n + 1;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.findTheWinner(5, 2) << endl;
	cout << solution.findTheWinner(6, 5) << endl;
}
