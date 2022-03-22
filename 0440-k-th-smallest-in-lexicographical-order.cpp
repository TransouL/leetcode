#include <iostream>

using namespace std;
#define min(a,b) ((a) < (b) ? (a) : (b))

class Solution {
	int getSteps(int curr, int n) {
		int steps = 0;
		int first = curr, last = curr, edge = n / 10;
		while (true) {
			steps += min(last, n) - first + 1;
			if (edge < first) {
				break;
			}
			else {
				first *= 10;
				last = last >= edge ? n : last * 10 + 9;
			}
		}
		return steps;
	}
public:
	int findKthNumber(int n, int k) {
		int curr = 1;
		--k;
		while (k > 0) {
			int steps = getSteps(curr, n);
			if (steps <= k) {
				k -= steps;
				++curr;
			}
			else {
				curr *= 10;
				k--;
			}
		}
		return curr;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.findKthNumber(13, 2) << endl;
	cout << solution.findKthNumber(1, 1) << endl;
}
