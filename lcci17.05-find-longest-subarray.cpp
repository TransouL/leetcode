#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> findLongestSubarray(vector<string>& array) {
		int ansLen = 0, ansLeft, diff = 0;
		unordered_map<int, int> idx;
		array.push_back("A");
		for (int i = 0; i < array.size(); i++) {
			if (idx.count(diff)) {
				int len = i - idx[diff];
				if (len > ansLen) {
					ansLen = len;
					ansLeft = idx[diff];
				}
			}
			else {
				idx[diff] = i;
			}
			if (isalpha(array[i][0])) {
				++diff;
			}
			else {
				--diff;
			}
		}
		if (ansLen) {
			return vector<string>(array.begin() + ansLeft, array.begin() + ansLeft + ansLen);
		}
		else {
			return {};
		}
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.findLongestSubarray(vector<string> {"A", "1", "B", "C", "D", "2", "3", "4", "E", "5", "F", "G", "6", "7", "H", "I", "J", "K", "L", "M"}));
	printVector(solution.findLongestSubarray(vector<string> {"A", "A"}));
	printVector(solution.findLongestSubarray(vector<string> {"A", "1"}));
}