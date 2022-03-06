#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
	vector<int> goodDaysToRobBank(vector<int>& security, int time) {
		int n = security.size();
		if (n < time * 2 + 1) {
			return {};
		}

		vector<int> ans;
		if (time == 0) {
			ans.resize(n);
			iota(ans.begin(), ans.end(), 0);
		}
		else {
			vector<int> nonIncreasingFrom(n, 0);
			int nonIncreasingHead = 0;
			int nonDecreasingHead = 0;
			for (int i = 1; i < n; i++) {
				if (security[i] > security[i - 1]) {
					nonIncreasingHead = i;
				}

				nonIncreasingFrom[i] = nonIncreasingHead;
				if (security[i] >= security[i - 1]) {
					int candDay = i - time;
					if (candDay >= nonDecreasingHead && nonIncreasingFrom[candDay] <= candDay - time){
						ans.emplace_back(candDay);
					}
				}
				else {
					nonDecreasingHead = i;
				}
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
	printVector(solution.goodDaysToRobBank(vector<int> {5, 3, 3, 3, 5, 6, 2}, 2));
	printVector(solution.goodDaysToRobBank(vector<int> {1, 1, 1, 1, 1}, 0));
	printVector(solution.goodDaysToRobBank(vector<int> {1, 2, 3, 4, 5, 6}, 2));
	printVector(solution.goodDaysToRobBank(vector<int> {1}, 5));
}
