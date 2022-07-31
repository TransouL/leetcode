#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string generateTheString(int n) {
		string ans;
		if (n & 1) {
			ans.append(n, 'a');
		}
		else {
			ans.append(n - 1, 'a');
			ans.append(1, 'b');
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.generateTheString(4) << endl;
	cout << solution.generateTheString(2) << endl;
	cout << solution.generateTheString(7) << endl;
}
