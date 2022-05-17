#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findKthNumber(int m, int n, int k) {
		int l = 1, r = m * n;
		while (l < r) {
			int x = l + (r - l) / 2;
			int count = x / n * n;
			for (int i = x / n + 1; i <= m; ++i) {
				count += x / i;
			}
			if (count >= k) {
				r = x;
			}
			else {
				l = x + 1;
			}
		}
		return l;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.findKthNumber(3, 3, 5) << endl;
	cout << solution.findKthNumber(2, 3, 6) << endl;
	cout << solution.findKthNumber(42, 34, 401) << endl;  //126
}
