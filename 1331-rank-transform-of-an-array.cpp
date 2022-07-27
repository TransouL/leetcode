#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

class Solution {
public:
	vector<int> arrayRankTransform(vector<int>& arr) {
		if (arr.empty()) {
			return{};
		}

		vector<pii> arrIdx;
		for (int i = 0; i < arr.size(); i++) {
			arrIdx.emplace_back(arr[i], i);
		}
		sort(arrIdx.begin(), arrIdx.end());

		vector<int> ans(arrIdx.size());
		int prev = arrIdx.front().first, prevIdx = 1;
		for (int i = 0; i < arrIdx.size(); i++) {
			if (arrIdx[i].first == prev) {
				ans[arrIdx[i].second] = prevIdx;
			}
			else {
				++prevIdx;
				ans[arrIdx[i].second] = prevIdx;
				prev = arrIdx[i].first;
			}
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
	printVector(solution.arrayRankTransform(vector<int>{ 40, 10, 20, 30 }));
	printVector(solution.arrayRankTransform(vector<int>{ 100, 100, 100 }));
	printVector(solution.arrayRankTransform(vector<int>{ 37, 12, 28, 9, 100, 56, 80, 5, 12 }));
	printVector(solution.arrayRankTransform(vector<int>{}));
}
