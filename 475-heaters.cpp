#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define max(a,b) ((a) > (b) ? (a) : (b))

class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int ans = 0;
		for (int i = 0, j = 0; i < houses.size(); ++i){
			while (j < heaters.size() - 1 && abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1]))
				j++;
			ans = max(ans, abs(houses[i] - heaters[j]));
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.findRadius(vector<int> {1, 2, 3}, vector<int> {2}) << endl;
	cout << solution.findRadius(vector<int> {1, 2, 3, 4}, vector<int> {1, 4}) << endl;
	cout << solution.findRadius(vector<int> {1, 5}, vector<int> {2}) << endl;
}
