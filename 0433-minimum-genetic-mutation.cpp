#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

char keys[4] = { 'A', 'T', 'C', 'G' };

class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		unordered_set<string> bankSet = { make_move_iterator(bank.begin()), make_move_iterator(bank.end()) };
		unordered_set<string> visited;
		if (start == end)
			return 0;
		if (!bankSet.count(end))
			return -1;
		queue<string> q;
		q.emplace(start);
		visited.emplace(start);
		int step = 1;
		while (!q.empty()) {
			int roundSize = q.size();
			for (int i = 0; i < roundSize; i++) {
				string curr = q.front();
				q.pop();
				for (int bit = 0; bit < 8; bit++) {
					for (int k = 0; k < 4; k++) {
						if (keys[k] != curr[bit]) {
							string next = curr;
							next[bit] = keys[k];
							if (next == end) {
								return step;
							}
							if (bankSet.count(next) && !visited.count(next)) {
								q.emplace(next);
								visited.emplace(next);
							}
						}
					}
				}
			}
			++step;
		}
		return -1;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.minMutation("AACCGGTT", "AACCGGTA", vector<string> {"AACCGGTA"}) << endl;
	cout << solution.minMutation("AACCGGTT", "AAACGGTA", vector<string> {"AACCGGTA", "AACCGCTA", "AAACGGTA"}) << endl;
	cout << solution.minMutation("AAAAACCC", "AACCCCCC", vector<string> {"AAAACCCC", "AAACCCCC", "AACCCCCC"}) << endl;
}
