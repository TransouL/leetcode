#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string pushDominoes(string dominoes) {
		int n = dominoes.size(), i = 0;
		char left = 'L';
		while (i < n) {
			int j = i;
			while (j < n && dominoes[j] == '.') {
				++j;
			}
			char right = j < n ? dominoes[j] : 'R';
			if (left == right) {
				for (int k = i; k < j; ++k) {
					dominoes[k] = left;
				}
			} else if (left == 'R' && right == 'L') {
				int k = j - 1;
				while (i < k) {
					dominoes[i++] = 'R';
					dominoes[k--] = 'L';
				}
			}

			i = j + 1;
			left = right;
		}
		return dominoes;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.pushDominoes("RR.L") << endl;
	cout << solution.pushDominoes(".L.R...LR..L..") << endl;
}
