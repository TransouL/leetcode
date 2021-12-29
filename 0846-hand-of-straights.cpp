#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int groupSize) {
		int n = hand.size();
		if (n % groupSize != 0)
			return false;
		sort(hand.begin(), hand.end());
		unordered_map<int, int> stats;
		for (auto &num : hand)
			++stats[num];
		for (auto &start : hand) {
			if (stats[start] == 0)
				continue;
			for (int num = start; num < start + groupSize; num++) {
				if (stats[num] == 0)
					return false;
				--stats[num];
			}
		}
		return true;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.isNStraightHand(vector<int> { 1, 2, 3, 6, 2, 3, 4, 7, 8 }, 3) << endl;
	cout << solution.isNStraightHand(vector<int> { 1, 2, 3, 4, 5 }, 4) << endl;
}
