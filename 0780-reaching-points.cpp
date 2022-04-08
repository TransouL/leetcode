#include <iostream>

using namespace std;

class Solution {
public:
	bool reachingPoints(int sx, int sy, int tx, int ty) {
		while (tx != ty && tx > sx && ty > sy) {
			if (tx > ty) {
				tx %= ty;
			}
			else {
				ty %= tx;
			}
		}
		if (tx == sx && ty == sy) {
			return true;
		}
		if (tx != sx && ty != sy) {
			return false;
		}
		if (tx == sx) {
			return ty > sy && (ty - sy) % sx == 0;
		}
		else {
			return tx > sx && (tx - sx) % sy == 0;
		}
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.reachingPoints(1, 1, 3, 5) << endl;
	cout << solution.reachingPoints(1, 1, 2, 2) << endl;
	cout << solution.reachingPoints(1, 1, 1, 1) << endl;
}
