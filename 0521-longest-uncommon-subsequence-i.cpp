#include <iostream>
#include <string>

using namespace std;
#define max(a,b) ((a) > (b) ? (a) : (b))

class Solution {
public:
	int findLUSlength(string a, string b) {
		return a == b ? -1 : max(a.size(), b.size());
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.findLUSlength("aba", "cdc") << endl;
	cout << solution.findLUSlength("aaa", "bbb") << endl;
	cout << solution.findLUSlength("aaa", "aaa") << endl;
}
