#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {
		int n = piles.size();
		int l = 1, r = *max_element(piles.begin(), piles.end());
		while (l < r) {
			int mid = l + (r - l) / 2;
			int tmp = 0;
			for (auto &pile : piles) {
				tmp += (pile + mid - 1) / mid;
			}
			if (tmp <= h) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		return l;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.minEatingSpeed(vector<int> {3, 6, 7, 11}, 8) << endl;
	cout << solution.minEatingSpeed(vector<int> {30, 11, 23, 4, 20}, 5) << endl;
	cout << solution.minEatingSpeed(vector<int> {30, 11, 23, 4, 20}, 6) << endl;
}
