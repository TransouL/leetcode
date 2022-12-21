#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maximumScore(int a, int b, int c) {
		int s = a, m = b, l;
		if (a > b) {
			s = b;
			m = a;
		}
		if (c <= s) {
			l = m;
			m = s;
			s = c;
		}
		else if (c < m){
			l = m;
			m = c;
		}
		else {
			l = c;
		}

		if (s + m <= l) {
			return s + m;
		}
		else {
			return l + s - (l - m + s + 1) / 2;
		}
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.maximumScore(2, 4, 6) << endl;
	cout << solution.maximumScore(4, 4, 6) << endl;
	cout << solution.maximumScore(1, 8, 8) << endl;
}