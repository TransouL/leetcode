#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
	unordered_map<int, int> b2w;
	int bound;

public:
	Solution(int n, vector<int>& blacklist) {
		int m = blacklist.size();
		bound = n - m;
		unordered_set<int> black;
		for (auto &b : blacklist) {
			if (b >= bound) {
				black.emplace(b);
			}
		}

		int mappingWhite = bound;
		for (auto &b : blacklist) {
			if (b < bound) {
				while (black.count(mappingWhite)) {
					++mappingWhite;
				}
				b2w[b] = mappingWhite++;
			}
		}
	}

	int pick() {
		int x = rand() % bound;
		return b2w.count(x) ? b2w[x] : x;
	}
};

int main(void){
	Solution solution = Solution(7, vector<int>{ 2, 3, 5 });
	for (int i = 0; i < 10; i++)
		cout << solution.pick() << endl;
}