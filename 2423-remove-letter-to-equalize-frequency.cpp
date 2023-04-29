#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool equalFrequency(string word) {
		int stats[26] = { 0 };
		for (auto &ch : word) {
			++stats[ch - 'a'];
		}
		unordered_map<int, int> freq;
		for (int i = 0; i < 26; i++) {
			if (stats[i]) {
				++freq[stats[i]];
			}
		}
		if (freq.size() == 1){
			return freq.begin()->first == 1 || freq.begin()->second == 1;
		}
		if (freq.size() > 2){
			return false;
		}
		auto it = freq.begin();
		int a = it->first, aCnt = it->second;
		++it;
		int b = it->first, bCnt = it->second;
		return ((a == 1 || a == b + 1) && aCnt == 1) || ((b == 1 || a + 1 == b) && bCnt == 1);
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.equalFrequency("abcc") << endl;
	cout << solution.equalFrequency("aazz") << endl;
	cout << solution.equalFrequency("abc") << endl;
	cout << solution.equalFrequency("abbcc") << endl;
	cout << solution.equalFrequency("ddaccb") << endl;
	cout << solution.equalFrequency("zz") << endl;
}