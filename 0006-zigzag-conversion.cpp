#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) {
			return s;
		}
		int n = s.size(), groupSize = numRows * 2 - 2;
		vector<string> z(numRows);
		for (int i = 0; i < n; ++i) {
			int groupIndex = i / groupSize, groupRemain = i % groupSize;
			int currRow;
			if (groupRemain < numRows) {
				currRow = groupRemain;
			}
			else {
				currRow = numRows - 1 - (groupRemain - numRows + 1);
			}
			z[currRow] += s[i];
		}
		string ans;
		for (auto &row : z){
			ans += row;
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.convert("PAYPALISHIRING", 3) << endl;
	cout << solution.convert("PAYPALISHIRING", 4) << endl;
	cout << solution.convert("A", 1) << endl;
	cout << solution.convert("ABCDE", 4) << endl;
}
