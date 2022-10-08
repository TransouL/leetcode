#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

class Solution {
public:
	vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		sort(nums1.begin(), nums1.end());
		vector<pii> enum2;
		for (int i = 0; i < n; i++) {
			enum2.emplace_back(nums2[i], i);
		}
		sort(enum2.begin(), enum2.end());

		vector<int> ans(n, 0);
		int l = 0, r = n - 1;
		for (int i = n - 1; i >= 0; --i) {
			if (enum2[i].first < nums1[r]) {
				ans[enum2[i].second] = nums1[r];
				--r;
			}
			else {
				ans[enum2[i].second] = nums1[l];
				++l;
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
	printVector(solution.advantageCount(vector<int> {2, 7, 11, 15}, vector<int> {1, 10, 4, 11}));
	printVector(solution.advantageCount(vector<int> {12, 24, 8, 32}, vector<int> {13, 25, 32, 11}));
}
