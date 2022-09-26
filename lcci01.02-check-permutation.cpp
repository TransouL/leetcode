#include <iostream>
using namespace std;

class Solution {
public:
	bool CheckPermutation(string s1, string s2) {
		if (s1.size() != s2.size()) {
			return false;
		}
		int cnt[26] = {0};
		for (int i = 0; i < s1.size(); i++) {
			++cnt[s1[i] - 'a'];
			--cnt[s2[i] - 'a'];
		}
		for (int i = 0; i < 26; i++) {
			if (cnt[i] != 0)
				return false;
		}
		return true;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.CheckPermutation("abc", "bac") << endl;
	cout << solution.CheckPermutation("abc", "bad") << endl;
}
