#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define min(a,b) ((a) < (b) ? (a) : (b))

class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		auto cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b) {
			return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
		};
		int m = nums1.size(), n = nums2.size();

		vector<vector<int>> ans;
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
		for (int i = 0; i < min(k, m); i++) {
			pq.emplace(i, 0);
		}
		while (k-- > 0 && !pq.empty()) {
			pair<int, int> p = pq.top();
			pq.pop();
			ans.emplace_back(initializer_list<int>{ nums1[p.first], nums2[p.second] });
			if (p.second + 1 < n) {
				pq.emplace(p.first, p.second + 1);
			}
		}

		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v)
		for (auto &n : e) cout << n << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.kSmallestPairs(vector<int> {1, 7, 11}, vector<int> {2, 4, 6}, 3));
	printVector(solution.kSmallestPairs(vector<int> {1, 1, 2}, vector<int> {1, 2, 3}, 2));
	printVector(solution.kSmallestPairs(vector<int> {1, 2}, vector<int> {3}, 3));
}
