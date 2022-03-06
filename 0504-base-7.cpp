#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string convertToBase7(int num) {
		bool isMinus = num < 0;
		if (isMinus) {
			num = -num;
		}
		string ans = to_string(num % 7);
		num /= 7;
		while (num > 0) {
			int remain = num % 7;
			ans.insert(0, to_string(remain));
			num /= 7;
		}
		if (isMinus) {
			ans.insert(0, "-");
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.convertToBase7(100) << endl;
	cout << solution.convertToBase7(-7) << endl;
}
