#include <iostream>

using namespace std;

class Solution {
public:
	bool rotateString(string s, string goal) {
		return s.size() == goal.size() && (s + s).find(goal) != string::npos;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.rotateString("abcde", "cdeab") << endl;
	cout << solution.rotateString("abcde", "abced") << endl;
}
