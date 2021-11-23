#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string originalDigits(string s) {
		size_t letters[26] = { 0 }, nums[10] = { 0 };
		for (auto ch : s) {
			++letters[ch - 'a'];
		}
		nums[0] = letters['z' - 'a'];
		nums[2] = letters['w' - 'a'];
		nums[4] = letters['u' - 'a'];
		nums[6] = letters['x' - 'a'];
		nums[8] = letters['g' - 'a'];

		nums[3] = letters['h' - 'a'] - nums[8];
		nums[5] = letters['f' - 'a'] - nums[4];
		nums[7] = letters['s' - 'a'] - nums[6];

		nums[1] = letters['o' - 'a'] - nums[0] - nums[2] - nums[4];

		nums[9] = letters['i' - 'a'] - nums[5] - nums[6] - nums[8];

		string ans;
		for (size_t i = 0; i < 10; i++){
			for (size_t j = 0; j < nums[i]; j++){
				ans += ('0' + i);
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.originalDigits("owoztneoer") << endl;
	cout << solution.originalDigits("fviefuro") << endl;
}