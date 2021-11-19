#include <iostream>

using namespace std;

class Solution {
public:
	int integerReplacement(int n) {
		int ans = 0;
		while (n != 1){
			if (n % 2 == 0){
				n /= 2;
				++ans;
			}
			else if (n % 4 == 1){
				n /= 2;
				ans += 2;
			}
			else {
				if (n == 3){
					n = 1;
					ans += 2;
				}
				else{
					n = n / 2 + 1;
					ans += 2;
				}
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.integerReplacement(8) << endl;
	cout << solution.integerReplacement(7) << endl;
	cout << solution.integerReplacement(4) << endl;
}