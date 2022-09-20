#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
	int kSimilarity(string s1, string s2) {
		int n = s1.size();
		queue<pair<string, int>> qu;
		unordered_set<string> visit;
		qu.emplace(s1, 0);
		visit.emplace(s1);
		for (int step = 0; ; step++) {
			int sz = qu.size();
			for (int i = 0; i < sz; i++) {
				auto p = qu.front();
				qu.pop();
				string cur = p.first;
				int pos = p.second;
				if (cur == s2) {
					return step;
				}
				while (pos < n && cur[pos] == s2[pos]) {
					++pos;
				}
				for (int j = pos + 1; j < n; j++) {
					if (cur[j] != s2[j] && cur[j] == s2[pos]) {
						swap(cur[pos], cur[j]);
						if (!visit.count(cur)) {
							visit.emplace(cur);
							qu.emplace(cur, pos + 1);
						}
						swap(cur[pos], cur[j]);
					}
				}
			}
		}
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.kSimilarity("ab", "ba") << endl;
	cout << solution.kSimilarity("abc", "bca") << endl;
}