#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool stoneGameIX(vector<int>& stones) {
		int cnt0 = 0, cnt1 = 0, cnt2 = 0;
		for (auto &stone : stones) {
			int type = stone % 3; 
			if (type == 0)
				++cnt0;
			else if (type == 1)
				++cnt1;
			else
				++cnt2;
		}
		if (cnt0 % 2 == 0)
			return cnt1 >= 1 && cnt2 >= 1;
		return cnt1 - cnt2 > 2 || cnt2 - cnt1 > 2;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.stoneGameIX(vector<int> {2, 1}) << endl;
	cout << solution.stoneGameIX(vector<int> {2}) << endl;
	cout << solution.stoneGameIX(vector<int> {5, 1, 2, 4, 3}) << endl;
}
