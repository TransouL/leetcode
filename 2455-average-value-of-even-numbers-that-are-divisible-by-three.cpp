#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int averageValue(vector<int>& nums) {
		int sum = 0, cnt = 0;
		for (auto &num : nums) {
			if ((num &1) == 0 && num % 3 == 0){
				sum += num;
				++cnt;
			}
		}
		return cnt == 0 ? 0 : sum / cnt;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.averageValue(vector<int> {1, 3, 6, 10, 12, 15}) << endl;
	cout << solution.averageValue(vector<int> {1, 2, 4, 7, 10}) << endl;
	cout << solution.averageValue(vector<int> {4, 4, 9, 10}) << endl;
}