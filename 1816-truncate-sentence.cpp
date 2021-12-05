#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string truncateSentence(string s, int k) {
		int len = s.size();
		for (size_t i = 0; i < s.size(); i++)
			if (s[i] == ' ')
				if (--k == 0)
					len = i;
		return s.substr(0, len);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.truncateSentence("Hello how are you Contestant", 4) << endl;
	cout << solution.truncateSentence("What is the solution to this problem", 4) << endl;
	cout << solution.truncateSentence("chopper is not a tanuki", 5) << endl;
}