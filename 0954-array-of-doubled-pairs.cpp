#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
	bool check(map<int, int> mp){
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			int num = it->first, count = it->second;
			if (count > 0) {
				if (mp[num * 2] < count) {
					return false;
				}
				mp[num * 2] -= count;
			}
		}
		return true;
	}
public:
	bool canReorderDoubled(vector<int>& arr) {
		map<int, int> mp1, mp2;
		int count0 = 0;
		for (auto &x : arr) {
			if (x == 0)
				++count0;
			else if(x > 0)
				++mp1[x];
			else
				++mp2[-x];
		}

		return !(count0 & 1) && check(mp1) && check(mp2);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.canReorderDoubled(vector<int> {3, 1, 3, 6}) << endl;
	cout << solution.canReorderDoubled(vector<int> {2, 1, 2, 6}) << endl;
	cout << solution.canReorderDoubled(vector<int> {4, -2, 2, -4}) << endl;
}
