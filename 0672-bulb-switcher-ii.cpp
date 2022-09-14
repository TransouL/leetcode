#include <iostream>
using namespace std;

class Solution {
	int getCand(int n) {
		switch (n) {
		case 1:
			return 2;
		case 2:
			return 3;
		default:
			return 4;
		}
	}

	int calc(int cand, int kinds) {
		if (kinds > cand) {
			return 0;
		}
		if (kinds == cand) {
			return 1;
		}
		switch (kinds) {
		case 1:
			return cand;
		case 2:
			return cand * (cand - 1) / 2;
		case 3:
			return 4;
		default:
			return -1;
		}
	}
public:
	int flipLights(int n, int presses) {
		int cand = getCand(n);
		int ans = 0;
		if (presses & 1) {
			ans += calc(cand, 1);
			if (presses >= 3){
				ans += calc(cand, 3);
			}
		}
		else {
			ans += 1;
			if (presses >= 2) {
				ans += calc(cand, 2);
			}
			if (presses >= 4) {
				ans += calc(cand, 4);
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.flipLights(1, 1) << endl;
	cout << solution.flipLights(2, 1) << endl;
	cout << solution.flipLights(3, 1) << endl;
	cout << solution.flipLights(4, 4) << endl;
}
