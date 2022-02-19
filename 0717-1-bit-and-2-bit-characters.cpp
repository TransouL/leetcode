#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		int n = bits.size(), i;
		if (n == 1) {
			return true;
		}
		for (i = n - 2; i >= 0 && bits[i]; --i) {}
		return (n - i) % 2 == 0;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.isOneBitCharacter(vector<int> {1, 0, 0}) << endl;
	cout << solution.isOneBitCharacter(vector<int> {1, 1, 1, 0}) << endl;
}
