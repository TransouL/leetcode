#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
		int ans = 0, n = energy.size();
		for (int i = 0; i < n; i++) {
			initialEnergy -= energy[i];
			if (initialExperience <= experience[i]) {
				ans += experience[i] - initialExperience + 1;
				initialExperience = experience[i] * 2 + 1;
			}
			else {
				initialExperience += experience[i];
			}
		}
		if (initialEnergy <= 0) {
			ans += 1 - initialEnergy;
		}
		return ans;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.minNumberOfHours(5, 3, vector<int> {1, 4, 3, 2}, vector<int> {2, 6, 3, 1}) << endl;
	cout << solution.minNumberOfHours(2, 4, vector<int> {1}, vector<int> {3}) << endl;
	cout << solution.minNumberOfHours(1, 1, vector<int> {1, 1, 1, 1}, vector<int> {1, 1, 1, 50}) << endl;
}