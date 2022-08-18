#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int maxEqualFreq(vector<int>& nums) {
		unordered_map<int, unordered_set<int>> stats;
		unordered_map<int, int> cnt;
		int ans = 2;
		for (int i = 0; i < nums.size(); i++) {
			int num = nums[i];
			if (cnt.count(num)) {
				int prev = cnt[num];
				int next = prev + 1;
				if (stats.count(next)) {
					stats[next].emplace(num);
				}
				else {
					unordered_set<int> nextSet;
					nextSet.emplace(num);
					stats.emplace(next, nextSet);
				}
				stats[prev].erase(num);
				if (stats[prev].empty()) {
					stats.erase(prev);
				}
				cnt[num] = next;
			}
			else {
				if (stats.count(1)) {
					cnt.emplace(num, 1);
					stats[1].emplace(num);
				}
				else {
					unordered_set<int> one;
					one.emplace(num);
					stats.emplace(1, one);
				}
				cnt.emplace(num, 1);
			}

			int statsSize = stats.size();
			if (statsSize == 1 && (stats.begin()->first == 1 || stats.begin()->second.size() == 1)) {
				ans = i + 1;
			}
			else if (statsSize == 2) {
				auto it = stats.begin();
				int key1 = it->first;
				++it;
				auto key2 = it->first;
				if (key1 > key2) {
					swap(key1, key2);
				}
				if ((key1 == 1 && stats[1].size() == 1) || (key2 - key1 == 1 && stats[key2].size() == 1)) {
					ans = i + 1;
				}
			}
		}

		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.maxEqualFreq(vector<int> {2, 2, 1, 1, 5, 3, 3, 5}) << endl;
	cout << solution.maxEqualFreq(vector<int> {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5}) << endl;
}
