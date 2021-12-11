#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string toLowerCase(string s) {
		for (auto &ch : s)
			if ('A' <= ch && ch <= 'Z')
				ch |= 32;
		return s;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.toLowerCase("Hello") << endl;
	cout << solution.toLowerCase("here") << endl;
	cout << solution.toLowerCase("LOVELY{}") << endl;
}