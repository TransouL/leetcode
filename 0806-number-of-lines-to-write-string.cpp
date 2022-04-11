#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> numberOfLines(vector<int>& widths, string s) {
		int line = 1, curr = 0;
		for (auto &ch : s) {
			curr += widths[ch - 'a'];
			if (curr > 100) {
				++line;
				curr = widths[ch - 'a'];
			}
		}
		return{ line, curr };
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.numberOfLines(vector<int>{10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, "abcdefghijklmnopqrstuvwxyz"));
	printVector(solution.numberOfLines(vector<int>{4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, "bbbcccdddaaa"));
	printVector(solution.numberOfLines(vector<int>{3, 4, 10, 4, 8, 7, 3, 3, 4, 9, 8, 2, 9, 6, 2, 8, 4, 9, 9, 10, 2, 4, 9, 10, 8, 2}, "mqblbtpvicqhbrejb"));
}
