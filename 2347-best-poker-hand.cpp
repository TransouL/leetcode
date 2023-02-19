#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string bestHand(vector<int>& ranks, vector<char>& suits) {
		if (suits[1] == suits[0] && suits[2] == suits[0] && suits[3] == suits[0] && suits[4] == suits[0]) {
			return "Flush";
		}
		int count[14] = { 0 };
		for (auto &&rank : ranks) {
			++count[rank];
		}
		bool hasPair = false;
		for (auto &&c : count) {
			if (c >= 3) {
				return "Three of a Kind";
			}
			if (c == 2) {
				hasPair = true;
			}
		}
		return hasPair ? "Pair" : "High Card";
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.bestHand(vector<int> {13, 2, 3, 1, 9}, vector<char> {'a', 'a', 'a', 'a', 'a'}) << endl;
	cout << solution.bestHand(vector<int> {4, 4, 2, 4, 4}, vector<char> {'d', 'a', 'a', 'b', 'c'}) << endl;
	cout << solution.bestHand(vector<int> {10, 10, 2, 12, 9}, vector<char> {'d', 'a', 'a', 'b', 'c'}) << endl;
}