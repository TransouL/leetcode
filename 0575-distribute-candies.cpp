#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int distributeCandies(vector<int>& candyType) {
		unordered_set<int> candyKindSet = { make_move_iterator(candyType.begin()), make_move_iterator(candyType.end()) };
		int Count = candyType.size();
		int KindCount = candyKindSet.size();
		return KindCount < Count / 2 ? KindCount : Count / 2;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.distributeCandies(vector<int> { 1, 1, 2, 2, 3, 3 }) << endl;
	cout << solution.distributeCandies(vector<int> { 1, 1, 2, 3 }) << endl;
}
