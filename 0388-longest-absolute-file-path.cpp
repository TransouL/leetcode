#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthLongestPath(string input) {
		int ans = 0;
		vector<int> folderLen;
		int currLevel = 0, currPathLen = 0, currLen = 0;
		bool isFile = false;
		for (auto &ch : input) {
			if (ch == '\n') {
				if (isFile) {
					ans = max(ans, currPathLen + currLen);
					isFile = false;
				}
				else {
					if (folderLen.size() > currLevel) {
						folderLen[currLevel] = currLen;
					}
					else {
						folderLen.emplace_back(currLen);
					}
				}
				currLevel = currPathLen = currLen = 0;
			}
			else if (ch == '\t') {
				currPathLen += folderLen[currLevel] + 1;
				++currLevel;
			}
			else if (ch == '.') {
				isFile = true;
				++currLen;
			}
			else {
				++currLen;
			}
		}
		if (isFile) {
			ans = max(ans, currPathLen + currLen);
		}

		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") << endl;
	cout << solution.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << endl;
	cout << solution.lengthLongestPath("a") << endl;
	cout << solution.lengthLongestPath("file1.txt\nfile2.txt\nlongfile.txt") << endl;
}
