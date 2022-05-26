#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findClosest(vector<string>& words, string word1, string word2) {
		int idx1 = -1, idx2 = -1, ans = 100001;
		for (int i = 0; i < words.size(); i++) {
			if (words[i] == word1) {
				idx1 = i;
				if (idx2 != -1) {
					ans = min(ans, idx1 - idx2);
					if (ans == 1)
						return 1;
				}
			}
			else if (words[i] == word2) {
				idx2 = i;
				if (idx1 != -1) {
					ans = min(ans, idx2 - idx1);
					if (ans == 1)
						return 1;
				}
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.findClosest(vector<string> {"I", "am", "a", "student", "from", "a", "university", "in", "a", "city"}, "a", "student") << endl;
}
