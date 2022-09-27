#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
	int getKthMagicNumber(int k) {
		priority_queue<long long, vector<long long>, greater<>> nums;
		nums.push(1);
		nums.push(3);
		long long ans = 0;
		for (int i = 0; i < k; i++) {
			ans = nums.top();
			while (ans == nums.top()) {
				nums.pop();
			}
			nums.push(ans * 3);
			nums.push(ans * 5);
			nums.push(ans * 7);
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.getKthMagicNumber(5) << endl;
	cout << solution.getKthMagicNumber(7) << endl;
}
