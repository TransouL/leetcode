#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string reformatNumber(string number) {
		vector<char> nums;
		for (auto &ch : number) {
			if (isdigit(ch)) {
				nums.emplace_back(ch);
			}
		}
		string ans;
		while (nums.size() > 4) {
			for (int i = 0; i < 3; i++) {
				ans += nums[0];
				nums.erase(nums.begin());
			}
			ans += '-';
		}
		if (nums.size() == 4) {
			ans += nums[0];
			ans += nums[1];
			ans += '-';
			ans += nums[2];
			ans += nums[3];
		}
		else {
			for (auto &ch : nums) {
				ans += ch;
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.reformatNumber("1-23-45 6") << endl;
	cout << solution.reformatNumber("123 4-567") << endl;
	cout << solution.reformatNumber("123 4-5678") << endl;
	cout << solution.reformatNumber("12") << endl;
	cout << solution.reformatNumber("--17-5 229 35-39475 ") << endl;
}
