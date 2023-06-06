#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

class Solution {
public:
	int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
		int n = reward1.size();
		vector<pii> rank(n);
		for (int i = 0; i < n; i++){
			rank[i] = make_pair(reward1[i] - reward2[i], i);
		}
		sort(rank.rbegin(), rank.rend());
		int ans = 0;
		for (int i = 0; i < k; i++) {
			ans += reward1[rank[i].second];
		}
		for (int i = k; i < n; i++) {
			ans += reward2[rank[i].second];
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.miceAndCheese(vector<int>{1, 1, 3, 4}, vector<int>{4, 4, 1, 1}, 2) << endl;
	cout << solution.miceAndCheese(vector<int>{1, 1}, vector<int>{1, 1}, 2) << endl;
}