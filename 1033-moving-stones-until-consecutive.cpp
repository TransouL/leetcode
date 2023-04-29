#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> numMovesStones(int a, int b, int c) {
		int big = a, m = b, s = c;
		if (a > b){
			if (c > b){
				if (a > c){
					m = c;
					s = b;
				}
				else {
					big = c;
					m = a;
					s = b;
				}
			}
		}
		else {
			if (c > b) {
				big = c;
				s = a;
			}
			else {
				big = b;
				if (a > c) {
					m = a;
				}
				else {
					m = c;
					s = a;
				}
			}
		}

		int diff1 = big - m, diff2 = m - s, mx = big - s - 2;
		if (diff1 == 1 && diff2 == 1){
			return{ 0, 0 };
		}
		if (diff1 == 1 || diff1 == 2 || diff2 == 1 || diff2 == 2) {
			return{ 1, mx };
		}
		return{ 2, mx };
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &&e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.numMovesStones(1, 2, 5));
	printVector(solution.numMovesStones(4, 3, 2));
	printVector(solution.numMovesStones(3, 5, 1));
}