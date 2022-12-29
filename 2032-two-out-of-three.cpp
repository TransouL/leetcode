#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
		int stats[101] = { 0 };
		for (auto &num : nums1) {
			stats[num] = 1;
		}
		for (auto &num : nums2) {
			stats[num] |= (1 << 1);
		}
		for (auto &num : nums3) {
			stats[num] |= (1 << 2);
		}
		vector<int> ans;
		for (int i = 1; i <=100; i++) {
			if (stats[i] == 3 || stats[i] == 5 || stats[i] == 6 || stats[i] == 7) {
				ans.emplace_back(i);
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

int main(void) {
	Solution solution = Solution();
	printVector(solution.twoOutOfThree(vector<int>{1, 1, 3, 2}, vector<int>{2, 3}, vector<int>{3}));
	printVector(solution.twoOutOfThree(vector<int>{3, 1}, vector<int>{2, 3}, vector<int>{1, 2}));
	printVector(solution.twoOutOfThree(vector<int>{1, 2, 2}, vector<int>{4, 3, 3}, vector<int>{5}));
}