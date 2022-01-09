#include <iostream>

using namespace std;

class Solution {
public:
	bool isAdditiveNumber(string num) {
		int n = num.size();
		for (int firstEnd = 0; firstEnd < n - 2; ++firstEnd) {
			if (num[0] == '0' && firstEnd != 0) {
				break;
			}
			for (int secondEnd = firstEnd + 1; secondEnd < n - 1; ++secondEnd) {
				if (num[firstEnd + 1] == '0' && secondEnd != firstEnd + 1) {
					break;
				}
				if (check(num, firstEnd, secondEnd)) {
					return true;
				}
			}
		}
		return false;
	}

	bool check(string num, int firstEnd, int secondEnd) {
		int n = num.size();
		int firstStart = 0, secondStart = firstEnd + 1;
		while (secondEnd < n - 1) {
			string third = stringAdd(num, firstStart, firstEnd, secondStart, secondEnd);
			int thirdStart = secondEnd + 1;
			int thirdEnd = secondEnd + third.size();
			if (thirdEnd >= n || num.substr(thirdStart, thirdEnd - thirdStart + 1) != third) {
				break;
			}
			if (thirdEnd == n - 1) {
				return true;
			}
			firstStart = secondStart;
			firstEnd = secondEnd;
			secondStart = thirdStart;
			secondEnd = thirdEnd;
		}
		return false;
	}

	string stringAdd(string s, int firstStart, int firstEnd, int secondStart, int secondEnd) {
		string res;
		int carry = 0, curr = 0;
		while (firstEnd >= firstStart || secondEnd >= secondStart || carry != 0) {
			curr = carry;
			if (firstEnd >= firstStart) {
				curr += s[firstEnd] - '0';
				--firstEnd;
			}
			if (secondEnd >= secondStart) {
				curr += s[secondEnd] - '0';
				--secondEnd;
			}
			carry = curr / 10;
			res.push_back(curr % 10 + '0');
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.isAdditiveNumber("112358") << endl;
	cout << solution.isAdditiveNumber("199100199") << endl;
}
