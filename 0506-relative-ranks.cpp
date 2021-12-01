#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const string awards[3] = { "Gold Medal", "Silver Medal", "Bronze Medal" };

class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& score) {
		size_t n = score.size();
		vector<pair<int, int>> scoreWithIndex;
		for (size_t i = 0; i < n; i++){
			scoreWithIndex.push_back(make_pair(score[i], i));
		}
		sort(scoreWithIndex.begin(), scoreWithIndex.end());
		
		vector<string> ans(n);
		for (size_t i = 0; i<n; ++i){
			if (i + 3 >= n)
				ans[scoreWithIndex[i].second] = awards[n - 1 - i];
			else
				ans[scoreWithIndex[i].second] = to_string(n - i); 
		}
		return ans;

	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.findRelativeRanks(vector<int> {5, 4, 3, 2, 1}));
	printVector(solution.findRelativeRanks(vector<int> {10, 3, 8, 9, 4}));
	printVector(solution.findRelativeRanks(vector<int> {1}));
}