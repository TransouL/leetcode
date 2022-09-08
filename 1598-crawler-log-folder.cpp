#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minOperations(vector<string>& logs) {
		int ans = 0;
		for (auto &log : logs) {
			if (log == "../") {
				if (ans > 0) {
					--ans;
				}
			}
			else if (log != "./") {
				++ans;
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.minOperations(vector<string> {"d1/", "d2/", "../", "d21/", "./"}) << endl;
	cout << solution.minOperations(vector<string> {"d1/", "d2/", "./", "d3/", "../", "d31/"}) << endl;
	cout << solution.minOperations(vector<string> {"d1/", "../", "../", "../"}) << endl;
	cout << solution.minOperations(vector<string> {"./", "../", "./"}) << endl;
}
