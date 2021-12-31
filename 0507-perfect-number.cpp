#include <iostream>

using namespace std;

class Solution {
public:
	bool checkPerfectNumber(int num) {
		if (num == 1)
			return false;
		int sum = 1;
		for (int i = 2; i*i <= num; i++){
			if (num % i == 0) {
				sum += i;
				if (i*i < num)
					sum += num / i;
			}
		}
		return sum == num;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.checkPerfectNumber(28) << endl;
	cout << solution.checkPerfectNumber(6) << endl;
	cout << solution.checkPerfectNumber(496) << endl;
	cout << solution.checkPerfectNumber(8128) << endl;
	cout << solution.checkPerfectNumber(2) << endl;
}
