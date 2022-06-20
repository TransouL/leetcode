#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string defangIPaddr(string address) {
		string ans;
		for (auto &ch : address) {
			if (ch == '.') {
				ans.append("[.]");
			}
			else {
				ans += ch;
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.defangIPaddr("1.1.1.1") << endl;
	cout << solution.defangIPaddr("255.100.50.0") << endl;
}