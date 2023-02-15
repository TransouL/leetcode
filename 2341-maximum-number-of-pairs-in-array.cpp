#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> numberOfPairs(vector<int>& nums) {
		unordered_map<int, int> stats;
		for (auto &num : nums) {
			++stats[num];
		}
		int pairs = 0, n = nums.size();
		for (auto it = stats.begin(); it != stats.end(); ++it) {
			pairs += it->second / 2;
		}
		return {pairs, n - pairs * 2};
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.numberOfPairs(vector<int> {1, 3, 2, 1, 3, 2, 2}));
	printVector(solution.numberOfPairs(vector<int> {1, 1}));
	printVector(solution.numberOfPairs(vector<int> {0}));
}